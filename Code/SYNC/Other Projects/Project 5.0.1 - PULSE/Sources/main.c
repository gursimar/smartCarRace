#include <hidef.h>
#include "mc9s12xd256.h"   

#include "global.h"
#include "atd.h"
#include "compensation.h"
#include "dcmotor.h"
#include "uart.h"
#include "servomotor.h"
#include "pid.h"
#include "counter.h"

#define MAX_CORRECTION 305
#define MIN_CORRECTION -305
#define GUARD_VAL 80

//#define KP          0.220           //max is 0.234375
//#define KI         0
#define KP 3

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
          
          // dc pid control
          unsigned int pulse_count=0;   //16 bit regsiter for accumulator
          int error_dc=0;     //error can be +ve or -ve
          unsigned char setpoint =0;    //set point is +ve and generally small values..
          int correction_dc=0;          //+ve or -ve
          unsigned char speed_dc = 80;
          unsigned char count=0;
          


          Leds_and_Switches_Init();
          ISR_init();
          ATD_init();
          dc_motor_init();                     // Current pwm duty is 55
          servo_init();
          pulse_counter_init();
          //uart0_9600_init();            //To be removed in the final version of the software.
          pulse_counter_init()
          
          setpoint = 1;

          for(;;)        
          {
                    //uart0_tx_string(" :::::::::::::: I'm now in main Loop !! :::::::::::: ");

                    

                    //This function compensates the sen_data array and puts the result into com_data array           
                    compensate_value(sen_data,com_data);
                    // Placing it here, will increase the lag between value read and action taken.. hence
                    // making the system unresponsive ...
                    ATD0CTL5_SCAN=0;          //This will start a new conversion ....
          
                    //I HAVE PLACED THIS HERE SO THAT THE TIME DIFFERENCE BETWEEN THE SPEED AND READINGS TAKEN
                    // IS MIN. THIS WAY THE SPEED AND READINGS WILL BE AT THE SAME SPOT....
                           
                           if(count >=10)
                           {
                                     count=0;
                                     pulse_count =  PACN10;
                                     PACN10=0;    //resets the pulse counter

                                     error_dc = setpoint - pulse_count;
                                     
                                     correction_dc =(int) ( KP*error_dc);
                                     
                                     
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
                           
                                                              	   
                    index=sort_array(com_data);
                    
                    if(com_data[index]<5)
                    {
                              i_stop++;
                              if(i_stop>=20)
                              {
                                        dc_motor_stop();
                              }
                    }
                    
                    //GUARD 1
                    else if(index ==0 && com_data[index]<GUARD_VAL)
                    {          
                              i_stop=0; //        to be reomved in final version of code
                              servo_set (1500+MIN_CORRECTION);
                              LED3=LED_ON;
                    }
                    
                    //GUARD 2
                    else if(index==6 && com_data[index]<GUARD_VAL)
                    {
                              i_stop=0; //        to be reomved in final version of code
                              servo_set (1500+MAX_CORRECTION);
                              LED3=LED_ON;
                    }
                    
                    else
                    {
                              i_stop=0; //        to be reomved in final version of code
                              LED3=LED_OFF;
                              position =  (index * 512) + (com_data[index-1]-com_data[index+1]) ;
                              error = 1536 - position;
                    
                              //PID        		               

                              // limits bound on iterm.
                              if (iterm>=30000)        //32767 is max limit of int
                              {
                                        //To buffer the fast responses of propotional control, we have the integral control.
                                        iterm = 30000;
                                        LED4=~LED4;
                              }

                              else if (iterm<=-30000)        //32767 is max limit of int
                              {
                                        //To buffer the fast responses of propotional control, we have the integral control.
                                        iterm = -30000;
                                        LED4=~LED4;
                              }

                              else
                              {
                                        iterm += error/10;
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
                              servo_output = 1500-(unsigned int)correction;
                              servo_set (servo_output);
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
  
  
