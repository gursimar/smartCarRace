#include <hidef.h>      
#include "mc9s12xd256.h"   

#include "global.h"
#include "atd.h"   
#include "compensation.h"
#include "dcmotor.h"
#include "uart.h"

void testmode(void);
void servo_centre();
void servo_init();
void servo_set(unsigned int);

#define KP          0.232           //max is 0.234375
#define MAX_CORRECTION 305
#define MIN_CORRECTION -305


unsigned char a[8],b[8];
unsigned char index;
unsigned int position=0;
int error=0;

unsigned int servo_output=1500;
float correction;

void main(void) 
{
           uart0_9600_init();
           leds_init_and_switches();           //Leds initialization
          //dc_motor_init();  	//Start Dc motors
          servo_init();
 
 
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
	             
	        compensate_value(a,b);      
	        // a contains true values
	        //b contains compensated values
	        
	                      testmode();
	
	             
/*	             b[0] = compensate_value(a[0],0);
	             b[1] = compensate_value(a[1],1);
	             b[2] = compensate_value(a[2],2);
	             b[3] = compensate_value(a[3],3);
	             b[4] = compensate_value(a[4],4);
	             b[5] = compensate_value(a[5],5);
	             b[6] = compensate_value(a[6],6);
	             b[7] = 0; // compensate_value(a[7],7);
*/	             
        		               
        		               
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

void get_pos()
{
                   index = sort_array(b);
                    
                    // As it is found, without inspecting the code that readings are set in dec order of indices
                    
                    position =  (index * 512) + (b[index+1]-b[index-1]) ;
           
                    error = 1536 - position;
                    correction = (KP*error);      //Only the propotional control

                    
                        
                        if (correction >= MAX_CORRECTION)
                          {
                              correction = MAX_CORRECTION;
                         }    
                         
                         if (correction <= MIN_CORRECTION)
                         {
                              correction = MIN_CORRECTION;
                         }
                         
                         servo_output = 1500-(unsigned int)correction;
                        //  servo_set (servo_output);
}

void testmode(void)
{
        char ans;
        
        //uart0_tx_newline();
        //uart0_tx_string("::::::::THE READINGS OF SENSORS ARE  :::::::::");
        //uart0_tx_newline();
        
        uart0_tx_string("$");
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
        uart0_tx_string("$");
        uart0_tx_newline();
        uart0_tx_newline();
        
        //COMPENSATED VALUES
        
        uart0_tx_string("$");
        uart0_tx_number(b[7]);        //Analog value channel 7
        uart0_tx_string("   ");
        uart0_tx_number(b[6]);        //Analog value channel 6
        uart0_tx_string("   ");
        uart0_tx_number(b[5]);        //Analog value channel 5
        uart0_tx_string("   ");
        uart0_tx_number(b[4]);        //Analog value channel 4
        uart0_tx_string("   ");
        uart0_tx_number(b[3]);        //Analog value channel 3
        uart0_tx_string("   ");
        uart0_tx_number(b[2]);        //Analog value channel 2
        uart0_tx_string("   ");
        uart0_tx_number(b[1]);        //Analog value channel 1
        uart0_tx_string("   ");
        uart0_tx_number(b[0]);        //Analog value channel 0
        uart0_tx_string("$");
        uart0_tx_newline();
        uart0_tx_newline();
       
        get_pos();
        
        // DATA OF ERROR
       /*
        uart0_tx_string("$");
       
        if(error<0)
        {
                    uart0_tx_string("-");
                    uart0_tx_int(-error);        //Analog value channel 0
        }
          else
                    uart0_tx_int(error);        //Analog value channel 0
        
        uart0_tx_string("$");
        uart0_tx_newline();
        uart0_tx_newline();
     */
          
//        THIS IS TO SEND POSITION DATA

        uart0_tx_string("$");
               
        uart0_tx_int(position);        //Sends the position data
        
        uart0_tx_string("$");
        uart0_tx_newline();
        uart0_tx_newline();

       /* uart0_tx_newline();
        
        uart0_tx_string(" servo output(by propotional correction only, without limits bound) is ::  ");
        uart0_tx_int(servo_output);        //Analog value channel 0
        
        
        uart0_tx_newline();
        uart0_tx_newline();
        
        // The values of the ATD register are resetted on the very first read .. ******
        */
       

        //uart0_tx_string("PRESS ANY KEY::   "); 
        ans=uart0_rx();

        //uart0_tx_newline();
        //uart0_tx_newline();
        
}
  
 void servo_init()
{
          PWMCTL_CON23=1;
        
        PWME_PWME2=1;                //PWM channel 2 Enable
        PWME_PWME3=1;                //PWM channel 3 Enable
        
        PWMPOL_PPOL2=1;              //PWM pulse High at begining of Period
        PWMPOL_PPOL3=1;              //PWM pulse High at begining of Period
        
        PWMCLK_PCLK2=1;              // clock SA as clock source for PWM
        PWMCLK_PCLK3=1;              // clock SB as clock source for PWM
        
            
        PWMPRCLK =0x00;              //clock A = 2MHz  clockB = 2MHz
        
        // Time of this clock pulse is 1 us
        PWMSCLA =1;                //clock  SA = clock A / (2 * 1) = 1MHz
        PWMSCLB =1;                //clock  SB = clock B / (2 * 1) = 1MHz
        
        // Value of the register as PWMPER2-PWMPER3 is 20,000.
        // So the value of period of the flipping is 20ms
        PWMPER2 = 0x4E;               // PWM Period 20ms           50Hz
        PWMPER3 = 0x20;               // PWM Period 20ms           50Hz
		  
     servo_centre();
}


void servo_centre()
{
	//	Values of registers is 1415
	 PWMDTY2 = 0x05;                // Pulse Width 1.5ms: Center Position
//	 PWMDTY3 = 0x87;                //1.415ms
	 
	 // Value of register os 1500....
	 PWMDTY3 = 0xDC;                //1.5ms
	 
       
}

void servo_set(unsigned int a)
{
	//	a should range somewhere in 1100 to 1700
	PWMDTY2 = (a>>8);
	a=a<<8;  
	a=a>>8;                
                       PWMDTY3 = a;      	
}



