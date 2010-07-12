#include <hidef.h>      
#include "mc9s12xd256.h"   

#include "global.h"
#include "atd.h"   
#include "compensation.h"
#include "dcmotor.h"

void main(void) 
{
            
            leds_init_and_switches();           //Leds initialization
	dc_motor_init();  	//Start Dc motors
	LED2=1;

	for(;;)        
	{
	            ATD0CTL5_SCAN=0;                    //This will start a new convesion
	
	             //calculate error by pid in pid.h should be implemented later
	
	             Delay(1);
	             
		
		 if(ATD0STAT0_SCF==1)    // on sequence completion
	             {
	            	LED2=0;
	                        if(compensate_value(ATD0DR7H,7)  <=5  && compensate_value(ATD0DR6H,6)  <=5  && compensate_value(ATD0DR5H,5)  <=5  && compensate_value(ATD0DR4H,4)  <=5  && compensate_value(ATD0DR3H,3)  <=5  && compensate_value(ATD0DR2H,2)  <=5  && compensate_value(ATD0DR1H,1)  <=5 && compensate_value(ATD0DR0H,0)  <=5)
        		            {
        			      //ATDSTAT0_SCF=0;		The flag clears automatically when we access status register and then the resukt register..
        			      dc_motor_stop();	//motor stop
        		            }
        		}
        	}
 
 }
