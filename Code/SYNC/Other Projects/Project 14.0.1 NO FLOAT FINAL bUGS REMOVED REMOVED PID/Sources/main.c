#include <hidef.h>
#include "mc9s12xd256.h"   

#include "global.h"
#include "atd.h"
#include "compensation.h"
#include "dcmotor.h"
#include "servomotor.h"
#include "eeprom.h"
#include "pid.h"
#include "timer.h"

#define MAX_CORRECTION 305
#define MIN_CORRECTION -305
#define GUARD_VAL 80

#define START_OR_CROSS    500
#define SURE_START    1300
#define ALL_WHITE 20

//  It depends on the KI max.......
#define ITERM_LIMIT  10000         // 32767                 // 21470000          //21474836-5000       assumed 100 as ki max..
#define SET_POINT 1510

#define SHARP_TURN      150
#define MIDDLE_TURN   70

#define KP_DC 10
#define KD_DC 7

void main(void)
{
          unsigned int position=0;
          int error=0,perror=0;
          long int iterm=0;

          //Declaration related to PID control systems.
          unsigned char com_data[7];

          unsigned int servo_output=1500;
          int correction;
          
          unsigned char lap=0;
          
          unsigned int totalsum;
          int start_count=0;  //variable to be removed...
                              
          Leds_and_Switches_Init();
          EEPROM_Init();
          //EEPROM_reset();
          EEPROM_read();
          
          dc_motor_init();                     // Current pwm duty is 85         
          ISR_init();
          ATD_init();
          pulse_counter_init();
          servo_init();
          //uart0_9600_init();            //To be removed in the final version of the software.
        //  TI1_Enable();
                                        
          while(1)
          {
                    //This function compensates the sen_data array and puts the result into com_data array.                    
                    compensate_value(sen_data,com_data);

                    // Placing it here, will increase the lag between value read and action taken.. hence
                    // making the system unresponsive ...
                    ATD0CTL5_SCAN=0;          //This will start a new conversion ....

	//START STOP DETEECTION
	//119	15	116	221	134	52	189           
                     totalsum = com_data[4]+com_data[5]+com_data[6]+com_data[0]+com_data[1]+com_data[2]+com_data[3];
                                          
                     if(totalsum>START_OR_CROSS && totalsum<SURE_START)    //either CROSS or start ...
                     {
                              //SUM OF SENSORS IS LARGE OS EITHER A CROSS OR START..
                              //LED1=LED_ON ;

                               if(start_count>delay_dc)
                               {
                                        if(lap>=2)
                                        {
                                                  dc_motor_stop();
                                                  //TSCR1_TEN = 0;                       // Stop timer
                                                  //dc_newval_flag=0;
                                        }
                                        else
                                        {
                                                  lap++;
                                        }
                                        
                               }                            
                                        
                    }
                    
                    //        CAN       BE        COMMENTED           IN        FINAL     VERSION   OF        CODE
                    else if(totalsum<ALL_WHITE)
                    {
                              //LED2=LED_ON ;                    
                              //do nothing..
                    }
                                                                       
                    else 
                    {
                              //LED3=LED_ON ;
                              start_count=0;                //for start/cross detection
                              
                              sort_array(com_data);
                                                                                        
                            /*To find the correction, we have three branches .... */
                                                                                        
                              //GUARD 1
                              if(index ==0 && com_data[index]<GUARD_VAL)
                              {          
                                        //LEFT
                                        //maore the 1500
                                        correction =MAX_CORRECTION;
                                        //LED4=LED_ON;
                              }
                              
                              //GUARD 2
                              else if(index==6 && com_data[index]<GUARD_VAL)
                              {
                                        //RIGHT
                                             // less than 1500
                                        correction =MIN_CORRECTION;
                                        //LED4=LED_ON;
                              }     
                              
                              else
                              {
                                        //LED3=LED_OFF;
                                        position =  (index << 9) + (com_data[index+1]-com_data[index-1]) ;
                                        perror=error;       //stores previous error
                                        error = 1536 - position;
                                                                      
                                        //PID        		               
                                        correction = (int)((int)((kp*error)/DIV100)  + (int)((ki *iterm)/DIV1000) + (int)(kd*(error-perror)/DIV1000));
                                        //anti wind up circutary
                                      
                                        if (correction >= MAX_CORRECTION)
                                        {
                                                  correction = MAX_CORRECTION;
                                        }    

                                        else if (correction <= MIN_CORRECTION)
                                        {
                                                  correction = MIN_CORRECTION;
                                        }
                                        else
                                        {
                                                  // limits bound on iterm.
                                                  if (iterm>=ITERM_LIMIT) 
                                                  {
                                                            //To buffer the fast responses of propotional control, we have the integral control.
                                                            iterm = ITERM_LIMIT;
                                                            //LED4=~LED4;
                                                  }

                                                  else if (iterm<=-ITERM_LIMIT)
                                                  {
                                                            //To buffer the fast responses of propotional control, we have the integral control.
                                                            iterm = -ITERM_LIMIT;
                                                            //LED4=~LED4;
                                                  }

                                                  else
                                                  {
                                                            iterm += error/20;
                                                  }                                                            
                                        }
                                                                                                                                                                
                              }
                                                            
                              servo_output = (unsigned int)(SET_POINT-correction);
                              servo_set(servo_output);
                    }
          }                              
}