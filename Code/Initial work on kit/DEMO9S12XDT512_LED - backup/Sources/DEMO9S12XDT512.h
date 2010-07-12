/******************************************************************************
*
*       Copyright (C) 2003 Freescale Semiconductor, Inc.
*       All Rights Reserved
*
* Filename:     DEMO9S12XDT512.h
* Author:       Nathan Lee - r61614
* Revision:     1.0a
*
* Description:	9S12XDT512 Demo Board Header File
*
* Notes:        Used in Projects DEMO9S12XDT512_LED.mcp and DEMO9S12XDT512_ATD.mcp
*
*******************************************************************************/

/* include peripheral declarations */
#include <mc9s12xdt512.h>

/* define value for LED's when on and off */
#define ON 0
#define OFF 1

/* define value for switches when up (not pressed) aon down (pressed) */
#define UP 1
#define DOWN 0

/* define LED's */
#define LED1 PORTB_PB4
#define LED2 PORTB_PB5
#define LED3 PORTB_PB6
#define LED4 PORTB_PB7


/* define SW's */
#define SW1 PTP_PTP0
#define SW2 PTP_PTP1
#define SW31 PORTB_PB0
#define SW32 PORTB_PB1
#define SW33 PORTB_PB2
#define SW34 PORTB_PB3

/* define ATD Inputs */
#define POT ATD1_PORTAD1_PTAD5
#define LIGHT ATD1_PORTAD1_PTAD4
