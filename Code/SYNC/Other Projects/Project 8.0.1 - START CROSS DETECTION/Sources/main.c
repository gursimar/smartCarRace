//START-STOP DETECTION - DONE
//PULSE ACCUMULATOR - PID -  DONE
//TO REMOVE 7TH SENSOR CODE 

#include <hidef.h>
#include "mc9s12xd256.h"   

#include "global.h"
#include "atd.h"
#include "compensation.h"
#include "dcmotor.h"
#include "uart.h"
#include "servomotor.h"
#include "eeprom.h"
#include "pid.h"

#define MAX_CORRECTION 305
#define MIN_CORRECTION -305
#define GUARD_VAL 80

#define START_CROSS 800
#define CUT_OFF_LR        23
#define START_CROSS_SURE_START 1200
#define ALL_WHITE  20

#define ITERM_LIMIT 10000
#define SET_POINT 1500

void testmode(void);
unsigned char com_data[8];

void main(void) 
{
          unsigned char index;
          unsigned int position=0;
          int error=0;

          //Declaration related to PID control systems.          
          int iterm=0;

          unsigned int servo_output=1500;
          float correction;
          
          int i_stop;
          
          unsigned int sumleft,sumright,totalsum;
          int start_count=0;  //variable to be removed...
          
          Leds_and_Switches_Init();
          IEE1_Init();
          //EEPROM_reset();
          EEPROM_read();
          
          ISR_init();
          ATD_init();
          dc_motor_init();                     // Current pwm duty is 85
          servo_init();
          //uart0_9600_init();            //To be removed in the final version of the software.
          
          for(;;)        
          {
                    //uart0_tx_string(" :::::::::::::: I'm now in main Loop !! :::::::::::: ");
                    
                    //This function compensates the sen_data array and puts the result into com_data array           
                    compensate_value(sen_data,com_data);
                              
                    // Placing it here, will increase the lag between value read and action taken.. hence
                    // making the system unresponsive ...
                    ATD0CTL5_SCAN=0;          //This will start a new conversion ....

	//START STOP DETEECTION
	//119	15	116	221	134	52	189
           
                     sumleft = com_data[0]+com_data[1]+com_data[2];
                     sumright = com_data[4]+com_data[5]+com_data[6];
                     totalsum = sumleft+sumright+com_data[3];
                     
                     if(totalsum>START_CROSS)    //either cross or start ...
                     {
                              //either start or cross
                              
                     
                              //if((sumright-sumleft) < CUT_OFF_LR && sumright-sumleft>0 || (sumleft-sumright) < CUT_OFF_LR && sumright-sumleft>0)
                              {
                                        // either 90 cross detected or satrt
                                        if(totalsum<START_CROSS_SURE_START)
                                        {
                                                   // Sure start
                                                   start_count ++;
                                                   if(start_count>delay_dc)
                                                   {
                                                            dc_motor_stop();
                                                   }
                                                   
                                        }
                                        else
                                        {
                                                  LED1=LED_ON    ;
                                                  start_count=0;
                                                  //sure 90 deg cross
                                                  //DO NOTHING...
                                        }
                                        
                                        
                              }
                              
                              //else
                              {
                                        //Sure non 90 cross
                                        //DO NOTHING
                              }
                              
                     }
                     
                     else if(totalsum<ALL_WHITE)
                     {
                              i_stop++;
                              if(i_stop>=100)     //STOP TIME
                              {
                                        dc_motor_stop();
                              }
                     }
                                         
                    else
                    {
                              start_count=0;
                              index=sort_array(com_data);	
                              i_stop=0;                             //To be removed in the final versions of the code
                              
                              /*
                              if(com_data[index]<15)
                              {
                                        //aa white
                              }
                              */
                              
                              //GUARD 1
                              if(index ==0 && com_data[index]<GUARD_VAL)
                              {          
                                        servo_set (1500+MIN_CORRECTION);
                                        LED3=LED_ON;
                              }
                              
                              //GUARD 2
                              else if(index==6 && com_data[index]<GUARD_VAL)
                              {
                                        servo_set (1500+MAX_CORRECTION);
                                        LED3=LED_ON;
                              }
                              
                              else
                              {
                                        //LED3=LED_OFF;
                                        position =  (index * 512) + (com_data[index+1]-com_data[index-1]) ;
                                        error = 1536 - position;
                              
                                        //PID        		               

                                        /*
                                        Done 10000 from 30000 because iterm once saturates becuse unhanlable .
                                        */

                                        // limits bound on iterm.
                                        if (iterm>=ITERM_LIMIT)        //32767 is max limit of int
                                        {
                                                  //To buffer the fast responses of propotional control, we have the integral control.
                                                  iterm = ITERM_LIMIT;
                                                  //LED4=~LED4;
                                        }

                                        else if (iterm<=-ITERM_LIMIT)        //32767 is max limit of int
                                        {
                                                  //To buffer the fast responses of propotional control, we have the integral control.
                                                  iterm = -ITERM_LIMIT;
                                                  //LED4=~LED4;
                                        }

                                        else
                                        {
                                                  iterm += error/30;
                                        }

                                        correction = (kp*error)  +  (ki *iterm);

                                        //anti wind up circutary
                                        if (correction >= MAX_CORRECTION)
                                        {
                                                  correction = MAX_CORRECTION;
                                        }    

                                        if (correction <= MIN_CORRECTION)
                                        {
                                                  correction = MIN_CORRECTION;
                                        }

                                        // 0      1         ....      5         6
                                        // -ve correction means -ve error (position-6) ie turn right
                                        // +ve correction means +ve error (position-0) ie turn left.
                                        servo_output = SET_POINT-(unsigned int)correction;
                                        servo_set (servo_output);
                              }
                    }
          }
}

void testmode(void)
{
        char ans;
        
        uart0_9600_init();

        uart0_tx_newline();
        uart0_tx_string("THE COMPENSATED READINGS ARE ::::::::::: TEST MODE ::::::: ");
        uart0_tx_newline();
       
        uart0_tx_number(com_data[7]);        //Analog value channel 7
        uart0_tx_string("   ");
        uart0_tx_number(com_data[6]);        //Analog value channel 6
        uart0_tx_string("   ");
        uart0_tx_number(com_data[5]);        //Analog value channel 5
        uart0_tx_string("   ");
        uart0_tx_number(com_data[4]);        //Analog value channel 4
        uart0_tx_string("   ");
        uart0_tx_number(com_data[3]);        //Analog value channel 3
        uart0_tx_string("   ");
        uart0_tx_number(com_data[2]);        //Analog value channel 2
        uart0_tx_string("   ");
        uart0_tx_number(com_data[1]);        //Analog value channel 1
        uart0_tx_string("   ");
        uart0_tx_number(com_data[0]);        //Analog value channel 0
        
        uart0_tx_newline();
        uart0_tx_newline();
       
        uart0_tx_string("::::::::THE READINGS OF SENSORS ARE  :::::::::");
        uart0_tx_newline();
        
        uart0_tx_number(ATD0DR7H);        //Analog value channel 7
        uart0_tx_string("   ");
        uart0_tx_number(ATD0DR6H);        //Analog value channel 6
        uart0_tx_string("   ");
        uart0_tx_number(ATD0DR5H);        //Analog value channel 5
        uart0_tx_string("   ");
        uart0_tx_number(ATD0DR4H);        //Analog value channel 4
        uart0_tx_string("   ");
        uart0_tx_number(ATD0DR3H);        //Analog value channel 3
        uart0_tx_string("   ");
        uart0_tx_number(ATD0DR2H);        //Analog value channel 2
        uart0_tx_string("   ");
        uart0_tx_number(ATD0DR1H);        //Analog value channel 1
        uart0_tx_string("   ");
        uart0_tx_number(ATD0DR0H);        //Analog value channel 0
        uart0_tx_newline();

        uart0_tx_string("PRESS ANY KEY::   ");
        ans=uart0_rx();

        uart0_tx_newline();
        uart0_tx_newline();
}
  
  
