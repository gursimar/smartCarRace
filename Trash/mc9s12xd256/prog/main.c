#include <hidef.h>      
#include "derivative.h"   

#include "global.h"
#include "atd.h"   
#include "compensation.h"
#include "dcmotor.h"

void main(void) 
{
	//Initialize ATD and leave it in automatic mode..
	dc_motor_init();	//Start Dc motors
	
	
	for(;;) 
		{
			  //calculate error by pid in pid.h
			  //eliminate errors by pid control
			  
			  if(ATD0DR7H<5 && ATD0DR6H<5 && ATD0DR5H<5 && ATD0DR4H<5 && ATD0DR3H<5 && ATD0DR2H<5 && ATD0DR1H<5 && ATD0DR0H<5 || )
        		{
        			dc_motor_stop();	//motor stop
        		
        		}
 
  }
}
