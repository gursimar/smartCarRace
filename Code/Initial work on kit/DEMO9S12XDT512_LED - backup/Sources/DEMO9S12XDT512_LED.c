/******************************************************************************
*
*       Copyright (C) 2005 Freescale Semiconductor, Inc.
*       All Rights Reserved
*
* Filename:     DEMO9S12XDT512_LED.c
* Author:       Nathan Lee - r61614
* Revision:     1.1
*
* Description:	Flashes LED1 and LED2 according to the position of SW1 and SW2.
*
* Notes:        Also serves as an example for the 9S12XDT512 demo board. 
*								Created using CodeWarrior v4.1 for S12X.
*
******************************************************************************/


#include <hidef.h>      /* common defines and macros */
#include <mc9s12xdt512.h>     /* derivative information */
#include <string.h>
#include "xgate.h"
#include "DEMO9S12XDT512.h" 	// Include the demo board declarations

#pragma LINK_INFO DERIVATIVE "mc9s12xdt512"

#define SOFTWARETRIGGER0_VEC  0x72 /* vector address= 2 * channel id */
#define ROUTE_INTERRUPT(vec_adr, cfdata)                \
  INT_CFADDR= (vec_adr) & 0xF0;                         \
  INT_CFDATA_ARR[((vec_adr) & 0x0F) >> 1]= (cfdata)
 
 
// ---------------------------------------------------------------------------
// XGate Setup Routine
// ---------------------------------------------------------------------------
static void SetupXGATE(void) {
  /* initialize the XGATE vector block and
     set the XGVBR register to its start address */
  XGVBR= (unsigned int)(void*__far)(XGATE_VectorTable - XGATE_VECTOR_OFFSET);

  /* switch software trigger 0 interrupt to XGATE */
  ROUTE_INTERRUPT(SOFTWARETRIGGER0_VEC, 0x81); /* RQST=1 and PRIO=1 */

  /* enable XGATE mode and interrupts */
  XGMCTL= 0xFBC1; /* XGE | XGFRZ | XGIE */

  /* force execution of software trigger 0 handler */
  XGSWT= 0x0101;
}

  
// ---------------------------------------------------------------------------
// Peripheral Initialization Routine
// ---------------------------------------------------------------------------
void PeriphInit(void)
{
    			
    DDRB_DDRB0 = 0;   // Port B[0..3] input (SW3 1-4)
    DDRB_DDRB1 = 0;
    DDRB_DDRB2 = 0;
    DDRB_DDRB3 = 0;
    DDRB_DDRB4 = 1;   // Port B[4..7] output (LED1-LED4)
    DDRB_DDRB5 = 1;
    DDRB_DDRB6 = 1;
    DDRB_DDRB7 = 1;
    
    LED1 = OFF;				// Turn Off LEDs
    LED2 = OFF;
    LED3 = OFF;
    LED4 = OFF;
        			
    DDRP_DDRP0 = 0;		// Port BP_0 and BP_1 equals input
    DDRP_DDRP1 = 0;   // SW1 and SW2
    
    PUCR_PUPBE = 1;   // Turn on the pullups for SW3 (1-4)
    
}


// ---------------------------------------------------------------------------
// Main
// ---------------------------------------------------------------------------
void main(void) 
{
	EnableInterrupts;
  SetupXGATE();
  PeriphInit();			// Microcontroller initialization
  	
	for (;;) {
    
    /**** Use SW1 and SW2 to control the LEDs ****/		
	  LED1 = SW1;			// Turns on or off LED1
		LED2 = SW1;			// Turns on or off LED2
		LED3 = SW2;			// Turns on or off LED3
		LED4 = SW2;			// Turns on or off LED4			
		
		
		/**** Use SW3 (1-4) to control the LEDs ****/
		//LED1 = SW31;			// Turns on or off LED1
		//LED2 = SW32;			// Turns on or off LED2
		//LED3 = SW33;			// Turns on or off LED3
		//LED4 = SW34;			// Turns on or off LED4
		
		
				
	}// Loop forever
	
}//end main(void)


