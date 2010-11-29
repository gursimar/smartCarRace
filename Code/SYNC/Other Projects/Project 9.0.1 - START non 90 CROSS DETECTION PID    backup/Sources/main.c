//START-STOP DETECTION - DONE
//PULSE ACCUMULATOR - PID -  DONE
//TO REMOVE 7TH SENSOR CODE   - DONE

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

#define START_CROSS           650
#define CUT_OFF_LR        250
#define START_NON90_SURE_START       1450
#define ALL_WHITE             20

#define ITERM_LIMIT 20000
#define SET_POINT 1500

#define KP_DC 3

void testmode(void);
unsigned char com_data[8];

void main(void) 
{
          unsigned char index;
          unsigned int position=0;
          int error=0,perror=0;

          //Declaration related to PID control systems.          
          int iterm=0;

          unsigned int servo_output=1500;
          float correction;
          
          int i_stop;
          
          unsigned int sumleft,sumright,totalsum;
          int start_count=0;  //variable to be removed...
          
                    // dc pid control
          unsigned int pulse_count=0;   //16 bit regsiter for accumulator
          int error_dc=0;     //error can be +ve or -ve
          int correction_dc=0;          //+ve or -ve
          unsigned char speed_dc = 80;
          unsigned char count=0;

          
          Leds_and_Switches_Init();
          IEE1_Init();
          //EEPROM_reset();
          EEPROM_read();
          
          ISR_init();
          ATD_init();
          pulse_counter_init();
          dc_motor_init();                     // Current pwm duty is 85
          servo_init();
          //uart0_9600_init();            //To be removed in the final version of the software.
          
          while(1)
          {
                    //uart0_tx_string(" :::::::::::::: I'm now in main Loop !! :::::::::::: ");
                    
                    //This function compensates the sen_data array and puts the result into com_data array           
                    compensate_value(sen_data,com_data);
                              
                    // Placing it here, will increase the lag between value read and action taken.. hence
                    // making the system unresponsive ...
                    ATD0CTL5_SCAN=0;          //This will start a new conversion ....

                    //code for PID of dc motor
                    if(count >=40)
                    {
                           count=0;
                           pulse_count =  PACN10;
                           PACN10=0;    //resets the pulse counter

                           error_dc = setpoint - pulse_count;
                           
                           correction_dc =(int) ( KP_DC*error_dc);
                           
                           
                           if(speed_dc + correction_dc>=200)
                           {
                              speed_dc=200;
                           }
                           else if(speed_dc + correction_dc <=0)
                           {
                              speed_dc =0;
                           }
                           else
                           {
                              speed_dc +=correction_dc;
                           }
                           dc_motor_speed(speed_dc);
                    }
                    count ++;


	//START STOP DETEECTION
	//119	15	116	221	134	52	189
           
                     sumleft = com_data[0]+com_data[1]+com_data[2];
                     sumright = com_data[4]+com_data[5]+com_data[6];
                     totalsum = sumleft+sumright+com_data[3];
                     
                     if(totalsum>START_CROSS)    //either CROSS or start ...
                     {
                              //SUM OF SENSORS IS LARGE OS EITHER A CROSS OR START..
                                                   
                              if(totalsum<START_NON90_SURE_START)
                              {
                                        //SO NOT ALL SENSORS ARE NOT ON BLACK .....
                                        // SO EITHER WE HAVE A NON 90 CROSS OR START
                                        if((sumright-sumleft) < CUT_OFF_LR && sumright-sumleft>0 || (sumleft-sumright) < CUT_OFF_LR && sumright-sumleft>0)
                                        {
                                                  // SUM LEFT AND SUM RIGHT IS ALMOST SAME..
                                                   //SURELY WE HAVE START ..
                                                   start_count ++;
                                                  // LED1=~LED1;
                                                   
                                                   if(start_count>delay_dc)
                                                   {
                                                            dc_motor_stop();
                                                   }
                                                   
                                        }
                                        else
                                        {
                                                  // SUM OF LEFT AND RIGHT IS NOT SAME
                                                  // SO THIS IS SURELY A NON 90 CROSS
                                                  start_count=0;
                                                  //LED2=~LED2;
                                        }
                                        
                                        
                              }
                              
                              else
                              {
                                        // QUITE A LARGE SUM OF ......
                                        //SURE 90 CROSS
                                        //DO NOTHING
                                        start_count=0;
                                      //  LED3=~LED3;

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
                                        perror=error;       //stores previous error
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
                                                  iterm += error/20;
                                        }

                                        correction = (kp*error)  +  (ki *iterm) + (kd*(perror-error));

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

        //uart0_tx_string("PRESS ANY KEY::   ");
        //ans=uart0_rx();

        //uart0_tx_newline();
        uart0_tx_newline();
}
  
  
