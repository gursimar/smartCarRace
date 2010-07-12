/*
 * vectortable.c
 * This file holds the interrupt vector table
 
 * $Author: a20639 $
 * $Date: 2005/08/11 20:46:23 $
 * $Name:  $
 */
#include "device_headers.h"

//*****************************
//Put your ISR routines here.
//extern interrupt void yourAppISR(void);

extern void near Vscirx(void);            //JCB


//Put the Function Name of your interrupt handler into this constant array.
//at the ISR location that you want.

#pragma CODE_SEG __NEAR_SEG NON_BANKED /* Interrupt section for this module. Placement will be in NON_BANKED area. */

__interrupt void UnimplementedISR(void)
{
  for(;;);
}

// Added redirected ISR vectors when BootLoader is enabled.
// The application cannot have a reset vector (resides in BootLoader).

#pragma CODE_SEG DEFAULT               /* Change code section to DEFAULT. */

  typedef void (*near tIsrFunc)(void);
  const tIsrFunc _vect[] @0xFF80 = {
        /* Interrupt table */
        UnimplementedISR,               /* Reserved                         */
        UnimplementedISR,               /* Reserved                         */
        UnimplementedISR,               /* Reserved                         */
        UnimplementedISR,               /* Reserved                         */
        UnimplementedISR,               /* Reserved                         */
        UnimplementedISR,               /* Reserved                         */
        UnimplementedISR,               /* PWM Emergency Shutdown           */
        UnimplementedISR,               /* Port P                           */
        UnimplementedISR,               /* Reserved                         */
        UnimplementedISR,               /* Reserved                         */
        UnimplementedISR,               /* Reserved                         */
        UnimplementedISR,               /* Reserved                         */
        UnimplementedISR,               /* Reserved                         */
        UnimplementedISR,               /* Reserved                         */
        UnimplementedISR,               /* Reserved                         */
        UnimplementedISR,               /* Reserved                         */
        UnimplementedISR,               /* Reserved                         */
        UnimplementedISR,               /* Reserved                         */
        UnimplementedISR,               /* Reserved                         */
        UnimplementedISR,               /* Reserved                         */
        UnimplementedISR,               /* Reserved                         */
        UnimplementedISR,               /* Reserved                         */
        UnimplementedISR,               /* Reserved                         */
        UnimplementedISR,               /* Reserved                         */
        UnimplementedISR,               /* CAN0 Transmit                    */
        UnimplementedISR,               /* CAN0 receive                     */
        UnimplementedISR,               /* CAN0 errors                      */
        UnimplementedISR,               /* CAN0 wake-up                     */
        UnimplementedISR,               /* FLASH                            */
        UnimplementedISR,               /* EEPROM                           */
        UnimplementedISR,               /* Reserved                         */
        UnimplementedISR,               /* Reserved                         */
        UnimplementedISR,               /* IIC Bus                          */
        UnimplementedISR,               /* BDLC                             */
        UnimplementedISR,               /* CRG Self Clock Mode              */
        UnimplementedISR,               /* CRG PLL Clock                    */
        UnimplementedISR,               /* Pulse Accumulator B Overflow     */
        UnimplementedISR,               /* Modulus Down Counter Underflow   */
        UnimplementedISR,               /* PortH                            */
        UnimplementedISR,               /* PortJ                            */
        UnimplementedISR,               /* ATD1                             */
        UnimplementedISR,               /* ATD0                             */
        Vscirx,                         /* SCI1                             */
        Vscirx,                         /* SCI0                             */
        UnimplementedISR,               /* SPI0                             */
        UnimplementedISR,               /* Pulse accumulator Input Edge     */
        UnimplementedISR,               /* Pulse Accumulator A Overflow     */
        UnimplementedISR,               /* Enhanced Capture Timer overflow  */
        UnimplementedISR,               /* Enhanced Capture Timer Ch7       */
        UnimplementedISR,               /* Enhanced Capture Timer Ch6       */
        UnimplementedISR,               /* Enhanced Capture Timer Ch5       */
        UnimplementedISR,               /* Enhanced Capture Timer Ch4       */
        UnimplementedISR,               /* Enhanced Capture Timer Ch3       */
        UnimplementedISR,               /* Enhanced Capture Timer Ch2       */
        UnimplementedISR,               /* Enhanced Capture Timer Ch1       */
        UnimplementedISR,               /* Enhanced Capture Timer Ch0       */
        UnimplementedISR,               /* Real Time Interrupt              */
        UnimplementedISR,               /* IRQ                              */
        UnimplementedISR,               /* XIRQ                             */
        UnimplementedISR,               /* SWI                              */
        UnimplementedISR,               /* Unimplemented instruction trap   */
        UnimplementedISR,               /* COP Failure reset                */
        UnimplementedISR                /* Clock Monitor fail Reset         */
        /*_Startup, by default in library*/ /* Reset vector */
   };
