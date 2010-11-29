/*
This function sets the motor speed by the use of PWM.
The argument to this function val 0<val<=200.
*/

void dc_motor_speed(unsigned char val)
{
          //PORTE_PE3=0;	//Disabling the Motor driver
          PWMDTY0 = val;                
          PWMDTY1 = 0;	
          //PORTE_PE3=0;	//Re-enabling the motor driver
}

void dc_motor_init()
{
  //Drives the motors in forward motion..		
        DDRE_DDRE2=1;              // Port E pin 2 & 3 set to output
        DDRE_DDRE3=1;
        DDRP_DDRP0=1;
        DDRP_DDRP1=1;

        PORTE_PE2=0;                
        PORTE_PE3=1;
        
        PWMPOL_PPOL0=1;              //PWM pulse High at begining of Period
        PWMPOL_PPOL1=1;              //PWM pulse High at begining of Period
        
        PWMCLK_PCLK0=1;              // clock SA as clock source for PWM
        PWMCLK_PCLK1=1;              // clock SB as clock source for PWM
        
        PWMPRCLK =0x00;              //clock A = 2MHz  clockB = 2MHz
        
        PWMSCLA =5;                //clock  SA = clock A / (2 * 5) = 200KHz
        PWMSCLB =5;                //clock  SB = clock B / (2 * 5) = 200KHz
    
        PWMPER0 = 200;               // PWM Period           1KHz
        PWMPER1 = 200;               // PWM Period           1KHz
        
        PWMDTY0 = 40;
        PWMDTY1 = 0;
        
        PWME_PWME0=1;                //PWM channel 0 Enable
        PWME_PWME1=1;                //PWM channel 1 Enable

}

void dc_motor_stop()
{
 // Stop Motor
        PORTE_PE3=0;
        
        PTP_PTP0=0;
        PTP_PTP1=0;
        PWME_PWME0=0;                //PWM channel disable
        PWME_PWME1=0;
}

void dc_motor_start()
{
 // Stop Motor
        PORTE_PE3=1;
        
        PTP_PTP0=1;
        PTP_PTP1=1;
        PWME_PWME0=1;                //PWM channel 0 Enable
        PWME_PWME1=1;                //PWM channel 1 Enable
}

void pulse_counter_init()
{
        PBCTL_PBEN=1;              //16 bit pulse accumulator enable bit (cascading two 8 bit pulse accumulator)
        
        TCTL4_EDG0B=1;        //configure the edge detector circuits
        TCTL4_EDG0A=0;        //10 is capture on falling edges only..
        
        DLYCT_DLY0=1;         //introduces delay of 1024 bus clock cycles..
        DLYCT_DLY1=1;
        PACN10=0;   //Sets the data register to 0.
}

               
