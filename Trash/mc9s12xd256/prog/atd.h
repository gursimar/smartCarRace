
void ATD_init()
{
	ATD0CTL1=0x87;                    // no external trigger
	ATD0CTL2_ADPU=1;                  // ATD Enable
	ATD0CTL2_ETRIGE=0;                // no external trigger
	ATD0CTL3_S8C=1;                   // 8 adc channels sequence
	ATD0CTL4_SRES8=1;                 // 8-bit Resolution
	ATD0CTL5=0x10;                    // multisequence
	
}
