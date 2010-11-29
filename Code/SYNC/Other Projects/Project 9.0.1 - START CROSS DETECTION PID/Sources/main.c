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
#define ALL_WHITE             20

#define ITERM_LIMIT 20000
#define SET_POINT 1500

#define SHARP_TURN      850
#define MIDDLE_TURN   400

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
          int correction;
          
          int i_stop;
          unsigned int a=0;             //To be removed in the final version of the code
          
          unsigned int totalsum;
          int start_count=0;  //variable to be removed...
          
          Leds_and_Switches_Init();
          EEPROM_Init();
          //EEPROM_reset();
          EEPROM_read();
          
          ISR_init();
          ATD_init();
          pulse_counter_init();
          servo_init();
          //uart0_9600_init();            //To be removed in the final version of the software.
          TI1_Enable();
          dc_motor_init();                     // Current pwm duty is 85
          
          ATD0CTL5_SCAN=1;    //CONTINUOUS mode
          while(1)
          {
                    //uart0_tx_string(" :::::::::::::: I'm now in main Loop !! :::::::::::: ");
                    //This function compensates the sen_data array and puts the result into com_data array.
                    compensate_value(sen_data,com_data);
                    
                    // Placing it here, will increase the lag between value read and action taken.. hence
                    // making the system unresponsive ...
                   // ATD0CTL5_SCAN=0;          //This will start a new conversion ....

	//START STOP DETEECTION
	//119	15	116	221	134	52	189
           
                     totalsum = com_data[4]+com_data[5]+com_data[6]+com_data[0]+com_data[1]+com_data[2]+com_data[3];
                     
                     if(totalsum>START_OR_CROSS && totalsum<SURE_START)    //either CROSS or start ...
                     {
                              //SUM OF SENSORS IS LARGE OS EITHER A CROSS OR START..
                              //LED1=LED_ON ;
                                                   
                               if(start_count>delay_dc)
                               {
                                        dc_motor_stop();
                               }                                                                                 
                                        
                    }
                              
                     else if(totalsum<ALL_WHITE)
                     {
                              //LED2=LED_ON ;
                              exit();
                              i_stop++;
                              if(i_stop>=100)     //STOP TIME
                              {
                                        //dc_motor_stop();
                              }
                     }
                                         
                    else 
                    {
                              //LED3=LED_ON ;
                              start_count=0;
                              i_stop=0;                             //To be removed in the final versions of the code
                              index=sort_array(com_data);	
                              
                              //code to be removed from here...
                              if(index <=1 || index>=5)
                              {
                                         setpoint=2;
                              }
                              else if(index==3)
                              {
                                        setpoint=3;
                              
                              }
                              else
                              {
                                        setpoint = 2;
                              }
                              
                                                            
                              //GUARD 1
                          /*    if(index ==0 && com_data[index]<GUARD_VAL)
                              {          
                                        servo_set (1500+MIN_CORRECTION);
                                        //LED4=LED_ON;
                                        //Delay(a);
                              }
                              
                              //GUARD 2
                              else if(index==6 && com_data[index]<GUARD_VAL)
                              {
                                        servo_set (1500+MAX_CORRECTION);
                                        //LED4=LED_ON;
                                        //Delay(a);
                              }     
                              
                              else*/
                              {
                                        //LED3=LED_OFF;
                                        position =  (index * 512) + (com_data[index+1]-com_data[index-1]) ;
                                        perror=error;       //stores previous error
                                        error = 1536 - position;
                                        
/*                                        if(error > SHARP_TURN || error<-SHARP_TURN)
                                        {
                                                  setpoint=2;
                                        }
                                        else if(error>MIDDLE_TURN || error<-MIDDLE_TURN)
                                        {
                                                  setpoint=3;
                                        }
                                        
                                        else 
                                        {
                                                  setpoint =4;
                                        }
*/                                             
                              
                                        //PID        		               
                                        correction = (int)((kp*error)  +  (ki *iterm) + (kd*(error-perror)));
                                        
                                        // PID of dc motor should be applied based on the result of the pid of SERVO
                                        // As the frequency of action of DC PID is slow,, 65 ms, so the lag is enough to drive the car out of track..
                                        

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
                                                            iterm += error/10;
                                                  }


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