/*
 * File:        s12slk.h
 * Purpose:     S12SLK definitions to APSLK I/O interfaces
 *
 * Notes:
 */

#ifndef APS12SLK_H
#define APS12SLK_H
#include "device_headers.h"

/* On-board interfaced components */
extern void SLK_PB_Init(void);
extern void SLK_LED_Init(void);

/************************************************************************************************/

/* Macros define the MCU Student Learning Kit Project Board (APSLK) user I/O interfaces
   to the appropriate registers / port pins on the APS12DT256SLK Application Module.
   Macros simplify the implementation of I/O interfaces in user code.
   Macros labeled with "Direct Connect" label are conveniently connected
   to the specified port pin via the APSLK and do not require jumper wire
   from MCU PORT to USER I/O header. Refer to the APSLK User Guide for
   more on this "Direct Connect" feature along with how to activate and/or
   disactivate the feature allowing the user to connect these user I/O
   interfaces to other MCU registers / port pins. Some I/O interfaces are
   left for the user to define. */
   
/* SLK PUSH BUTTONS */
#define SLK_PB1  PTP_PTP0         //Direct Connect
#define SLK_PB2  PTP_PTP1			    //Direct Connect
#define SLK_PB3  -1               //Not Available on the Application Module
#define SLK_PB4  -1               //Not Available on the Application Module
//The variables have -1 assigned so that the main.c code will never
//enter the if-then condition for PB[3:4]. This is done to avoid compile errors.

/* SLK LEDs */
#define SLK_LED1 PORTB_BIT4       //LED1 on the Application Module          
#define SLK_LED2 PORTB_BIT5			  //LED2 on the Application Module
#define SLK_LED3 PORTB_BIT6       //LED3 on the Application Module
#define SLK_LED4 PORTB_BIT7       //LED4 on the Application Module


 /* SLK SWITCHES */
#define SLK_SW1_1 UNDEFINED          //PBMCUSLK Switches do NOT support "Direct Connect" feature 
#define SLK_SW1_2 UNDEFINED					//User must use jumper wire to connect to I/O
#define SLK_SW1_3 UNDEFINED					//PBMCUSLK_SWx_x macros are placeholders to define I/O pin
#define SLK_SW1_4 UNDEFINED
#define SLK_SW2_1 UNDEFINED
#define SLK_SW2_2 UNDEFINED
#define SLK_SW2_3 UNDEFINED
#define SLK_SW2_4 UNDEFINED
#define SLK_SWs   UNDEFINED          //Macro can be assigned to a single I/O port for byte-wide decoding

/* Application Module POT */
#define SLK_POT  ATD0DR5H             //Direct Connect to PTAD_PTAD1 also ATD Ch.1

/* SLK Timer */
#define TIMER_COUNT  PACN32             //Direct Connect to PTAD_PTAD1 also ATD Ch.1

/* SLK SCI Registers for the S12C Module*/
/* Requires DB9 Cable connected to PC Terminal*/
/* Terminal Settings: 
/* Baud: 9600, Data Bits: 8, Parity: None, Stop Bits: 1, Flow Control: None*/

#define PBMCUSLK_SCIDRL   SCI0DRL          //PBMCUSLK Switches do NOT support "Direct Connect" feature 
#define PBMCUSLK_SCIBDH   SCI0BDH					//User must use jumper wire to connect to I/O
#define PBMCUSLK_SCIBDL   SCI0BDL					//PBMCUSLK_SWx_x macros are placeholders to define I/O pin
#define PBMCUSLK_SCICR1   SCI0CR1
#define PBMCUSLK_SCICR2   SCI0CR2
#define PBMCUSLK_SCITC    SCI0SR1_TC
#define PBMCUSLK_SCITDRE  SCI0SR1_TDRE
#define PBMCUSLK_SCIRDRF  SCI0SR1_RDRF
#define PBMCUSLK_SCISR1   SCI0SR1

/* APSLK INITIALIZATION */
#define INIT_SLK_PBs       AppMod_PB_Init()      //Initializes pins as inputs to read PBx level
#define INIT_SLK_LEDs      AppMod_LED_Init()     //Initializes pins as outputs to write LEDx level
#define INIT_SLK_POT       AppMod_POT_Init()        //Initializes ATD to sample POT value
#define INIT_SLK_COM       AppMod_COM_Init()        //Initializes SCI to Rx/Tx data thru COM port to terminal
#define INIT_SLK_FRTimer   AppMod_Timer_Init()      //Initalized the Free Running Timer
#define INIT_SLK_BUZZER    AppMod_BUZZER_Init()

//The source code below require interface with the Project Board
//or custom external circuitry.

#define SLK_BUZZER_VOLUME TC0Lo 

/* SLK LCD Registers for the S12C Module*/
/* Requires the Freescale Project Board or custom external LCD interface*/
#define PBMCUSLK_SPIDR    SPI0DR          //PBMCUSLK Switches do NOT support "Direct Connect" feature 
#define PBMCUSLK_SPIBR    SPI0BR					//User must use jumper wire to connect to I/O
#define PBMCUSLK_SPIBDL   SCI0BDL					//PBMCUSLK_SWx_x macros are placeholders to define I/O pin
#define PBMCUSLK_SPICR1   SPI0CR1
#define PBMCUSLK_SPICR2   SPI0CR2
#define PBMCUSLK_SPISR    SPI0SR


/* Miscellaneous Macros */
#define DDRE_DDRE0_MASK 1
#define ON  0         /*Depending on Wiring Schematic..This works best for LEDs on this board*/
#define OFF 1         /*Depending on Wiring Schematic..This works best for LEDs on this board*/

/* Example use of macro definitions in user application:
   
   //Code Example
   if (!APSLK_PB1)
   {
      APSLK_LED1 = ON;
      APSLK_BUZZER_VOLUME = APSLK_POT;
   }
   else
   {
      APSLK_LED2 = ON;
      APSLK_BUZZER_TONE = APSLK_POT;
   }
   
  **Explanation of Code Example**
  If APSLK_PB1 is equal to zero, turn on APSLK_LED1. Then read the current APSLK_POT
  value sampled by ATD Ch.1 and write it to the APSLK_BUZZER_VOLUME, which sets the PWM Ch.0
  duty cycle. If APSLK_PB1 is not equal to zero, turn on APSLK_LED2 and write APSLK_POT 
  value sampled by ATD Ch. 1 and write it to the APSLK_BUZZER_TONE, which sets the PWM Ch.0
  period. */
  
#endif /* APS12DT256SLK_H */