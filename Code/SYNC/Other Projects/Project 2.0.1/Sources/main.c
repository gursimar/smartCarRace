#include <hidef.h>
#include "mc9s12xd256.h"   

#include "global.h"
#include "atd.h"
#include "compensation.h"
#include "dcmotor.h"
#include "uart.h"
#include "servomotor.h"

#define MAX_CORRECTION 305
#define MIN_CORRECTION -305

#define KP          0.220           //max is 0.234375
#define KI         0


void testmode(void);


unsigned char sen_data[8],com_data[8];

void main(void) 
{
          unsigned char index[3];
          unsigned int position=0;
          int error=0;
          
          //Declaration related to PID control systems.          
          int iterm=0;
          float kp=0,ki=0;
          unsigned int servo_output=1500;
          float correction;
          
          leds_init_and_switches();
          ATD_init();
          dc_motor_init();                     // Current pwm duty is 50
          servo_init();
//          uart0_9600_init();            //To be removed in the final version of the software.
          LED2=1;

	for(;;)        
	{

                              //This will start a new convesion
	            ATD0CTL5=0x10;                    // multisequence
	            Delay(1);
	           
	             if(ATD0STAT0_SCF==1)    // on sequence completion
	             {
	                    //Assign the values to the array
	                    sen_data[0] =  ATD0DR0H;
	                    sen_data[1] =  ATD0DR1H;
	                    sen_data[2] =  ATD0DR2H;
	                    sen_data[3] =  ATD0DR3H;
	                    sen_data[4] =  ATD0DR4H;
	                    sen_data[5] =  ATD0DR5H;
	                    sen_data[6] =  ATD0DR6H;
	                    sen_data[7] =  ATD0DR7H;
	           
	                    //This function compensates the sen_data array and puts the result into com_data array           
	                    compensate_value(sen_data,com_data);      
	            	LED2=0;
	                   
	                     if(com_data[0]  <=5  && com_data[1]  <=5  && com_data[2]  <=5  && com_data[3] <=5  && com_data[4]  <=5  && com_data[5]  <=5  && com_data[6]  <=5 && com_data[7] <=5)
	                     {       
        		                    
        		                    //The flag clears automatically when we access status register and then the resukt register..          
        		                    //ATDSTAT0_SCF=0;		
        			              
        			          //dc_motor_stop();
               	                    }
        		 
        		 // esle if(comm_data[] >=240 {do nothing}           
        		   else
                                           {
        		               sort_array(com_data,index);
        		               position =  (index[1] * 512) + (com_data[0]-com_data[2]) ;
        		               error = 1536 - position;
        		               
        		               //PID        		               
        		               iterm += error ;
        		               
        		               // limits bound on iterm.
        		               if (iterm>=32765)        //32767 is max limit of int
        		               {
        		                    //To buffer the fast responses of propotional control, we have the integral control.
        		                    iterm = 32765;
        		               }
        		               
        		               correction = (KP*error) + (KI *iterm) ; 
        		               
        		               if (correction >= MAX_CORRECTION)
        		               {
        		                    correction = MAX_CORRECTION;
        		               }    
        		               
        		               if (correction <= MIN_CORRECTION)
        		               {
        		                    correction = MIN_CORRECTION;
        		               }
        		               
        		               // -ve correction means -ve error, ie turn right
        		               // +ve correction means +ve error ie turn left.
        		               servo_output = 1500-(unsigned int)correction;
        		              servo_set (servo_output);
        		        
        		    }
                              }
        		
                              else 
                              {
                    	     //uart0_tx_string("Conversion sequence not complete..");
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
  
  
