#include <hidef.h>         /* common defines and macros */
#include "LCD.h"
#include "SCI.h"

/*YOU MUST, Open and edit the header file below, for different MCU targets*/
#include "device_headers.h" /*Chip specific defines and macros*/


// The AP_ utilizes the features and USB-BDM
// of only the Application Module 
// To be used when the application module is stand-alone.

//  The PB_ utilizes the features and USB-BDM 
//  of the Project Board
//  To be used when the application module is connected to the
//  Project Board.



//#pragma CODE_SEG DEFAULT


void main(void) {
  
  INIT_SLK_PBs;
  INIT_SLK_LEDs;
  INIT_SLK_POT;
  INIT_SLK_BUZZER; //Only Available when interfaced to Project Board
  INIT_SLK_FRTimer;
  LCDInit();       //Only Available when interfaced to Project Board
  SCIInit();
  
  EnableInterrupts;
  
   LCDPutString("  FSL\n");
   LCDPutString(" HCS12\n");
   SCITransmitStr("\r\rFreescale HCS12 Demo\n\r");     
  for(;;) {
    
    /* PB1 = LED1 */
    if (SLK_PB1 == 0)
    {
      SLK_LED1 = ON;	     //LED 1 Active
      LCDPutString(" LED 1\n");
      LCDPutString("ENABLED\n");
    } 
    /* PB2 = LED2 */
    else if(SLK_PB2 == 0)
    {
      SLK_LED2 = ON;     //LED 2 Active
      LCDPutString(" LED 2\n");
      LCDPutString("ENABLED\n");
      }
      /*Buzzer and PWM */ 
    else if(SLK_PB3 == 0)
    {
      LCDPutString("BUZZER\n");
      LCDPutString("ENABLED\n");
      TCTL2_OM0 = 1;
      SLK_BUZZER_VOLUME = SLK_POT +1;      
      } 
      /*The Bouncing Switch*/
    else if(SLK_PB4 == 0)
    {
     SLK_LED4 = !SLK_LED4;  //Needs Switch De-bounce!!
      }
      /*The Blinking LED*/ 
    else if(PAFLG_PAOVF == 1)    //Polling Free Timer Overflow flag   
      {
      SLK_LED3 = !SLK_LED3;
      PAFLG_PAOVF = 1;              //Clearing the Overflow flag
      TIMER_COUNT = 0x7fff;            //Setting count to 0x7FFF to increase flash rate.
     }
    else{   
     TCTL2_OM0 = 0;
      SLK_LED2 = OFF;
      SLK_LED1 = OFF;
      LCDPutString("  FSL\n");
      LCDPutString(" HCS12\n");
   
    }
       } /* wait forever */
}


  

