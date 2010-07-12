#include <hidef.h>
#include "mc9s12xd256.h"   

#include "global.h"
#include "atd.h"
#include "compensation.h"
#include "dcmotor.h"
#include "uart.h"

void testmode(void);


unsigned char sen_data[8],com_data[8];

void main(void) 
{
          unsigned char index[3];
          int position,error;
          
          float kp,ki;
          int iterm;
          
          leds_init_and_switches();
	dc_motor_init();  
	LED2=1;

	for(;;)        
	{

                      //This will start a new convesion
	           ATD0CTL5_SCAN=0;                  
	           Delay(1);
	           
	           //This function compensates the sen_data array and puts the result into com_data array           
	           compensate_value(sen_data,com_data);      
	           
		
	  	 if(ATD0STAT0_SCF==1)    // on sequence completion
	             {
	            	LED2=0;
	                   
	                     if(com_data[0]  <=5  && com_data[1]  <=5  && com_data[2]  <=5  && com_data[3] <=5  && com_data[4]  <=5  && com_data[5]  <=5  && com_data[6]  <=5 && com_data[7] <=5)
	                     {       
        		                    
        		                    //The flag clears automatically when we access status register and then the resukt register..          
        		                    //ATDSTAT0_SCF=0;		
        			              
        			          dc_motor_stop();
        		           }
        		            
        		           else
        		           {
        		               sort_array(com_data,index);
        		               position =  index[1] * 2 * 256 * (com_data[index[2]]-com_data[index[0]]) ;
        		               error = 1536 - position;
        		               
        		               //PID        		               
        		               iterm += error ;
        		               correction = (kp*error) + (ki *iterm) ; 
        		               
        		               if (correction > MAX_VALUE)
        		                    correction = MAX_VALUE;
        		               
        		               else if (correction <0)
        		                    correction = 0;
        		               
        		               else
        		               {
        		                    //Routines to find correction
        		               }
        	                    
        		            
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
  
  
