void ATD_init()
{
	        /*                    THIS WORKS          ONLY IN THIS MODULE .......
          ATD0CTL1=0x87;                    // no external trigger
          ATD0CTL2_ADPU=1;                  // ATD Enable
          ATD0CTL2_ETRIGE=0;                // no external trigger
          ATD0CTL3_S8C=1;                   // 8 adc channels sequence
          ATD0CTL4_SRES8=1;                 // 8-bit Resolution
               */

	// New code to implement interrupts
	
	//ATD0CTL2 registers
	ATD0CTL2_ADPU=1;   //ATD Power Up
	
	ATD0CTL2_AFFC=1;   //The flag CCF clears automatically if we read the appropriate result register
	
	//No need to use it. It will decrease the response of the system
	//ATD0CTL2_AFFC=0;   //The flag clears when we read the ATDSTAT1
	
	ATD0CTL2_ASCIE=1;  //The interrupt will be called when ASCIF is 1. Clearing this flag is necessary.
	
	//ATD0CTL3
	//ATD0CTL3_S8C=1;           // 8 adc channels sequence
	
	
	ATD0CTL3_S8C=0;           // 7 ADC channels sequence
	ATD0CTL3_S4C=1;           // from 0-7 
	ATD0CTL3_S2C=1;           // 
	ATD0CTL3_S1C=1;           // 
                    
	
                    //ATD0CTL4
                    ATD0CTL4_SRES8=1;  //8 bit resoluation
                    
                     //Fastest possible settings already
                    ATD0CTL4_SMP=0;     //2 clock cycles.
                    ATD0CTL4_PRS=0;    //divinde BUS clock by 2. However the MAX BUS clock is 4mhz and min is 2mhx
                    
                    //ATD0CTL5
                    ATD0CTL5_DJM=0;     //Left Justified
                    ATD0CTL5_MULT=1;
                    ATD0CTL5_SCAN=0;    //single conversion mode
                    //ATD0CTL5_SCAN=1;    //CONTINUOUS mode
}