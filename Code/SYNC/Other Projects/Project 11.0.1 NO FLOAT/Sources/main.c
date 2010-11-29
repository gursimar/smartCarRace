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

#define START_OR_CROSS           600
#define SURE_START       1300

//  It depends on the KI max.......
#define ITERM_LIMIT 21470000          //21474836-5000       assumed 100 as ki max..
#define SET_POINT 1500

#define SHARP_TURN      850
#define MIDDLE_TURN   400

#define KP_DC 1
#define KD_DC 323


void main(void)
{
          unsigned char index;
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
          
          // DC pid control variables
          int error_dc,perror_dc=0;     //error can be +ve or -ve
          int correction_dc=0;          //+ve or -ve
          unsigned char speed_dc = 80;
          unsigned char count=0;
          
          Leds_and_Switches_Init();
          EEPROM_Init();
          EEPROM_reset();
          EEPROM_read();
          
          ISR_init();
          ATD_init();
          pulse_counter_init();
          servo_init();
          //uart0_9600_init();            //To be removed in the final version of the software.
          //TI1_Enable();
          dc_motor_init();                     // Current pwm duty is 85         
          
          //ATD0CTL5_SCAN=1;    //CONTINUOUS mode
          while(1)
          {
                    //This function compensates the sen_data array and puts the result into com_data array.
                    compensate_value(sen_data,com_data);
                    
                    // Placing it here, will increase the lag between value read and action taken.. hence
                    // making the system unresponsive ...
                    ATD0CTL5_SCAN=0;          //This will start a new conversion ....
                   
                   
                     // CODE FOR DC_PID CONTROL.. 
                    if(dc_newval_flag)
                    {
                              perror_dc=error_dc;
                              error_dc = setpoint - pulse_count;

                              dc_newval_flag=0;                  
                             correction_dc =(int) ( (KP_DC*error_dc )+ (KD_DC*(error_dc-perror_dc)/DIV100));
                                                      
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
                                        // A type of integrator
                                        speed_dc +=correction_dc;
                              }
                              dc_motor_speed(speed_dc);
                    }

	//START STOP DETEECTION
	//119	15	116	221	134	52	189           
                     totalsum = com_data[4]+com_data[5]+com_data[6]+com_data[0]+com_data[1]+com_data[2]+com_data[3];
            /*                              
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
                                                                       
                    else */
                    {
                              //LED3=LED_ON ;
                              start_count=0;
                              index=sort_array(com_data);
                              
                          /*To find the correction, we have three branches .... */
                                                            
                              //GUARD 1
                          /*    if(index ==0 && com_data[index]<GUARD_VAL)
                              {          
                                        correction =MIN_CORRECTION;
                                        //LED4=LED_ON;
                                        //Delay(a);
                              }
                              
                              //GUARD 2
                              else if(index==6 && com_data[index]<GUARD_VAL)
                              {
                                        correction =MAX_CORRECTION;
                                        //LED4=LED_ON;
                                        //Delay(a);
                              }     
                              
                              else*/
                              {
                                        //LED3=LED_OFF;
                                        position =  (index << 9) + (com_data[index+1]-com_data[index-1]) ;
                                        perror=error;       //stores previous error
                                        error = 1536 - position;
                                                                      
                                        //PID        		               
                                        correction = (int)((kp*error)/DIV100  + (int)((ki *iterm)/DIV10000) + kd*(error-perror)/DIV100);
                                        
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
                                                            iterm += error;
                                                  }                                                  
                                        }
                                        
                                       /* PID of dc motor should be applied based on the result of the pid of SERVO ie ""correction""
                                            As the frequency of action of DC PID is slow,, 65 ms, so the lag is enough to drive the car out of track..
                                            DIRECT ACCESS TO DC MOTOR SHOULD BE MADE .. while settiing thr """setpoint"""
                                       */
                                        
                                        if(correction > SHARP_TURN || correction<-SHARP_TURN)
                                        {
                                                  dc_motor_speed(20);
                                                  setpoint=2;
                                        }
                                        else if(correction>MIDDLE_TURN || correction<-MIDDLE_TURN)
                                        {
                                                  dc_motor_speed(40);
                                                  setpoint=3;
                                        }
                                        
                                        else 
                                        {
                                                  dc_motor_speed(50);
                                                  setpoint =4;
                                        }
                                             


                                        // 0      1         ....      5         6
                                        // -ve correction means -ve error (position-6) ie turn right
                                        // +ve correction means +ve error (position-0) ie turn left.
                                        servo_output = SET_POINT-correction;
                                        servo_set (servo_output);
                              }
                    }
          }
}