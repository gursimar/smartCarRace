/*
 * File:        s12slk.c
 * Purpose:     S12SLK initialization routines to configure APSLK I/O interfaces
 *
 * Notes:
 */

#include "AP_s12dt256slk.h"

/* Local function prototypes */
/* On-board interfaced components */
void AppMod_PB_Init(void);
void AppMod_LED_Init(void);
void AppMod_POT_Init(void);

/************************************************************************************************/
/* Initialization routine to configure pins as inputs to read PBx level. */
void AppMod_PB_Init(void)
{
  /* Makes PTP[0:1] an input pin to allow the user to read APSLK_PB2 in application. */
  DDRP &= ~DDRP_DDRP1_MASK;
  DDRP &= ~DDRP_DDRP0_MASK;
  PERP_PERP1 = 1;
  PERP_PERP0 = 1;         
}
/************************************************************************************************/
/* Initialization routine to configure pins as outputs to write LEDx level. */
void AppMod_LED_Init(void)
{
  /* Makes PTB[4:5] output pins to allow the user to turn on/off APSLK_LED[2]
     in application. */
  DDRB_BIT4 = 1;
  DDRB_BIT5 = 1;
  DDRB_BIT6 = 1;
  DDRB_BIT7 = 1;
  /* Insert user code here to initialize UNDEFINED APSLK LEDs */
}
/************************************************************************************************/
  /* Initialization routine to setup IOC1 as a free running Timer*/
void AppMod_Timer_Init(void)
{
TSCR1_TEN = 1;    //Enable the timer
PACTL_PAMOD = 1;  //Enable the PA Clock
PACTL_PEDGE = 1;  //Use 64-bit Divider when IOC7 is low.
PAFLG_PAOVF = 1;  //Clear the Overflow flag
PACTL_PAEN = 1;   //Enable the Pulse Accumulator
PACN32 = 0x7FFF; //Overflows at 0XFFFF.  Change this number to vary flash rate.
}
/************************************************************************************************/
/* Initialization routine to setup ATD to sample POT value. */
void AppMod_POT_Init(void)
{
  /* Initializes ATD Channel 1 to continously sample PBMCUSLK Potentiometer to allow the 
     user to read PBMCUSLK_POT, which holds the instantaneous ATD Ch.1 data result. */                
  ATD0CTL2 |= (ATD0CTL2_ADPU_MASK |       //ATD power up enabled
              ATD0CTL2_AFFC_MASK);				//ATD fast flag clear enabled
                                        //ATD interrupts disabled
  ATD0CTL3 &= ~ATD0CTL3_S4C_MASK;					//ATD conversions per sequence = 8
                                        //ATD in non-fifo mode, freeze disabled
  ATD0CTL4 |= ATD0CTL4_SRES8_MASK;        //ATD set to 8-bit resolution
                                        //ATD sample time =  2 ATD conv.clock periods
  ATD0CTL4 &= ~(ATD0CTL4_PRS2_MASK);      //ATD Clock = Bus Clock / [2 * (prescaler + 1)]
                                        //ATD Clock = 8MHz / [2 * (1+1)] = 2MHz
  ATD0CTL5 |= (ATD0CTL5_SCAN_MASK |				//ATD scan mode enabled
              ATD0CTL5_CA_MASK |
              ATD0CTL5_CC_MASK);					//ATD single channel scan of ATD Ch.1
                                        //ATD result is left-justified and unsigned  
}
/************************************************************************************************/

/* Initialization routine to setup PWM to drive BUZZER freq and duty cycle. */
void AppMod_BUZZER_Init(void)
{
//Only available when using the Freescale Project Board
}
/* Initialization routine to setup PWM to drive BUZZER freq and duty cycle. */
void AppMod_COM_Init(void)
{
//Only available when using the Freescale Project Board
}

