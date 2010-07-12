
void ATD_init()
{
	ATD0CTL1=0x87;            // No external trigger
	
	//Writes to this register also starts a new conversion while aborts the current
	ATD0CTL2_ADPU=1;          // ATD Enable
	ATD0CTL2_ADPU=0;          // Power down ATD
	
	ATD0CTL2_ETRIGE=0;        // No external trigger
	ATD0CTL3_S8C=1;           // 8 adc channels sequence
	ATD0CTL4_SRES8=1;         // 8-bit Resolution
	
	//Writes to ADT0CTL5 rgister will abort the current conversion and will start a new conversion
	
	ATD0CTL5_MULT=1;          // multisequence
//	ATD0CTL5_SCAN=1;          //CONTINUOUS MODE
	ATD0CTL5_SCAN=0;          //SINGLE MODE
	
	//ATD0CTL5_DJM=1;         //RIGHT JUSTIFIED RESULT. This is needed only if 10 bit resolution is used
}
