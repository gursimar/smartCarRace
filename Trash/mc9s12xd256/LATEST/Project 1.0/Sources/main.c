#include <hidef.h>      
#include "mc9s12xd256.h"   

#include "global.h"
#include "atd.h"   
#include "compensation.h"
#include "dcmotor.h"
#include "uart.h"

void testmode(void);

int a[8];


void main(void) 
{

           uart0_9600_init();
           leds_init_and_switches();           //Leds initialization
	//dc_motor_init();  	//Start Dc motors
 
 
 ATD0CTL1=0x87;                    // no external trigger
        ATD0CTL2_ADPU=1;                  // ATD Enable
        ATD0CTL2_ETRIGE=0;                // no external trigger
        ATD0CTL3_S8C=1;                   // 8 adc channels sequence
        ATD0CTL4_SRES8=1;                 // 8-bit Resolution
        
	for(;;)        
	{
	        ATD0CTL5=0x10;                    // multisequence
                    //This will start a new convesion
	
	           
	             Delay(1);
	             
	             a[0] =  ATD0DR0H;
	             a[1] =  ATD0DR1H;
	             a[2] =  ATD0DR2H;
	             a[3] =  ATD0DR3H;
	             a[4] =  ATD0DR4H;
	             a[5] =  ATD0DR5H;
	             a[6] =  ATD0DR6H;
	             a[7] =  ATD0DR7H;
	             
	              testmode();
		 /*
	  	 if(ATD0STAT0_SCF==1)    // on sequence completion
	             {
	                    if(compensate_value(ATD0DR7H,7)  <=5  && compensate_value(ATD0DR6H,6)  <=5  && compensate_value(ATD0DR5H,5)  <=5  && compensate_value(ATD0DR4H,4)  <=5  && compensate_value(ATD0DR3H,3)  <=5  && compensate_value(ATD0DR2H,2)  <=5  && compensate_value(ATD0DR1H,1)  <=5 && compensate_value(ATD0DR0H,0)  <=5)
        		            {          //ATDSTAT0_SCF=0;		The flag clears automatically when we access status register and then the resukt register..
        			              
        			             //calculate error
        			             LED2=1;

        			              //dc_motor_stop();	//motor stop
        		            }
        		}
        		*/
        	}
     
 }


void testmode(void)
{
        char ans;
        
        uart0_tx_newline();
        uart0_tx_string("::::::::THE READINGS OF SENSORS ARE  :::::::::");
        uart0_tx_newline();
        
        
        uart0_tx_number(a[7]);        //Analog value channel 7
        uart0_tx_string("   ");
        uart0_tx_number(a[6]);        //Analog value channel 6
        uart0_tx_string("   ");
        uart0_tx_number(a[5]);        //Analog value channel 5
        uart0_tx_string("   ");
        uart0_tx_number(a[4]);        //Analog value channel 4
        uart0_tx_string("   ");
        uart0_tx_number(a[3]);        //Analog value channel 3
        uart0_tx_string("   ");
        uart0_tx_number(a[2]);        //Analog value channel 2
        uart0_tx_string("   ");
        uart0_tx_number(a[1]);        //Analog value channel 1
        uart0_tx_string("   ");
        uart0_tx_number(a[0]);        //Analog value channel 0
        uart0_tx_newline();
        
        uart0_tx_newline();
        uart0_tx_string("THE COMPENSATED READINGS ARE ::::::::::: TEST MODE ::::::: ");
        uart0_tx_newline();
        
        
        uart0_tx_number(compensate_value(a[7],7));        //Analog value channel 7
        uart0_tx_string("   ");
        uart0_tx_number(compensate_value(a[6],6));        //Analog value channel 6
        uart0_tx_string("   ");
        uart0_tx_number(compensate_value(a[5],5));        //Analog value channel 5
        uart0_tx_string("   ");
        uart0_tx_number(compensate_value(a[4],4));        //Analog value channel 4
        uart0_tx_string("   ");
        uart0_tx_number(compensate_value(a[3],3));        //Analog value channel 3
        uart0_tx_string("   ");
        uart0_tx_number(compensate_value(a[2],2));        //Analog value channel 2
        uart0_tx_string("   ");
        uart0_tx_number(compensate_value(a[1],1));        //Analog value channel 1
        uart0_tx_string("   ");
        uart0_tx_number(compensate_value(a[0],0));        //Analog value channel 0
        
        uart0_tx_newline();
        uart0_tx_newline();
        
        // The values of the ATD register are resetted on the very first read .. ******
       
       

        uart0_tx_string("PRESS ANY KEY::   ");
        ans=uart0_rx();

        uart0_tx_newline();
        uart0_tx_newline();

}
  
  