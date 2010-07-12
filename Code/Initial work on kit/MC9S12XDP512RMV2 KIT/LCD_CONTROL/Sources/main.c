/************************************************************
AUTHOR _ GURSIMRAN SINGH
XLNC
THAPAR UNIVERSITY

This program displays text on the LCD of the project board ..
*************************************************************/

#include <hidef.h>      /* common defines and macros */
#include <mc9s12xdt512.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12xdt512"


void main(void) {
  /* put your own code here */
  EnableInterrupts;
  LCDInit();
  LCDPutString("SIMAR");

  for(;;) {} /* wait forever */
  /* please make sure that you never leave this function */
}
