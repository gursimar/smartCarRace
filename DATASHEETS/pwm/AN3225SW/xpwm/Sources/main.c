/******************************************************************************
Copyright (c) Freescale Semiconductor 2006
File Name		 :	$RCSfile: main.c,v $
Current Revision :	$Revision: 1.10 $
Notes            :  
*******************************************************************************/
/* include files */
#include "per_XDx512_L15Y.h"
#include "xgate_vectors.h"

/******************************************************************************
Function Name	:	PLLStartup
Arguments		:	freq: 
Return			:	
Notes			:	Ref Clock is assumed to be 1MHz
******************************************************************************/
//#define REFDV 15					/* 16 MHz crystal */
//#define REFDV 11					  /* 12 MHz crystal */
#define REFDV 3					  /* 4 MHz crystal */
void PLLStartup(tU08 freq) {
									/* switch to OSCCLK */
	CRG.clksel.byte = 0;
 	CRG.pllctl.byte = CME   |		/* clock monitor enabled */
  				  		    PLLON |		/* PLL on */
	  			     			AUTO	|		/* automatic bandwidth control enabled */
		  		      		SCME;			/* self clock mode enabled */
	if(freq != 0) {
	  								/* configure PLL */
										/* fref = fosc / (REFDV+1) */
	  CRG.refdv.byte = REFDV;
									/* fvco = 2*fref*(SYNR+1) */
	  CRG.synr.byte = freq - 1;
									/* wait for lock FOR EVER! */
	  while(CRG.crgflg.bit.lock != SET);
		if(CRG.crgflg.bit.lock == SET) {
									/* switch to PLLCLK */
			CRG.clksel.byte |= PLLSEL;
  	}
	}
}


/******************************************************************************
Function Name	:	XGATE_Init
Parameters		:	None
Returns			:	None
Notes			:	
******************************************************************************/
void XGATE_Init(void) {
  XGATE.xgvbr = (int)((void*__far)XGATEVectorTable)-0x00c0;	/* initialise XGATE vector base */
  XGATE.xgmctl = 0xff00 | XGE | XGFRZ | XGIE;					/* interrupt enable, enable XGATE, stop XGATE in freeze mode */
}

/******************************************************************************
Function Name	:	SetIntPrio
Parameters		:	None
Returns			:	None
Notes			:	channel is equal to lower byte of vector address 
                    i.e. Reset is channel 0xFE, SCI0 is channel 0xD6, etc. 
******************************************************************************/
void SetIntPrio(char channel, char prio)	{
	Interrupt.int_cfaddr = (channel << 1) & 0xf0;
	Interrupt.int_cfdata[channel & 0x07].byte = prio;
}


/******************************************************************************
Function Name	:	PWM_Init
Parameters		:	None
Returns			:	None
Notes			:	CPU Initialisation for PWM - ports and PIT
******************************************************************************/
void PWM_Init(void)
{
  DDRA.byte = 0xFF;                           // Set to output for PWM channels
  DDRB.byte = 0x01;                           // Set to output for PWM channels
//  DDRC.byte = 0xFF;                           // Set to output for PWM channels
//  DDRD.byte = 0xFF;                           // Set to output for PWM channels

  PIT.pitce.bit.pce2 = 1;				              // Enable PIT channel 2 
	PIT.pitmtld1.byte = 0;				              // Divide by 1 
	PIT.pitmux.bit.pmux2 = 1;                   // Assign PIT channel 2 to microtimer 1  
  PIT.pitld2.word = 1320-1;		                // 150Hz @ 0.5% -> 33us/25ns   = 1320 
	PIT.pitcflmt.byte = PITE | PITFRZ | PFLMT1;	// Enable the PIT module and force reload of the micro counter
	PIT.pitflt.bit.pflt2 = 1;			              // Force reload of counter 2     
  PIT.pitinte.bit.pinte2 = 1;		              // Enable interrupts from channel 2 
}

void main(void)
{
  PLLStartup(40);	              // Set Fbus to 40MHz 
  XGATE_Init();                 // Init XGATE, copy code to RAM, etc

  SetIntPrio(0x39, RQST|1);	    // Assign Software Interrupt channel 0 to XGATE, priority 1
  SetIntPrio(0x3b, RQST|1);	    // Assign PIT2 channel to XGATE, priority 1
  
#ifdef INITIALISE_BY_XGATE
    /* Call XGATE software interrupt 0 to initialise XGATE driver */
  XGATE.xgswt.word = XGSWT0M | XGSWT0;
#else
    /* Initialise on the CPU */
  PWM_Init();									  // Initialise PWM
#endif

  while(1);											// !!! DO NOTHING AND LET THE XGATE DO THE PWM !!!
}


