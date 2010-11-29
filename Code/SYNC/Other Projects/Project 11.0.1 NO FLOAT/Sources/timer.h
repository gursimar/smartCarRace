/*
"OnInterrupt"  event is called periodically with the period that you specify.

**         TimerInt supports also changing the period in runtime.

**         The source of periodic interrupt can be timer compare or reload
**         register or timer-overflow interrupt (of free running counter).

**     Settings  :
**         Timer name                  : ECT_Counter (16-bit)
**         Compare name                : TC0
**         Counter shared              : No
**
**         High speed mode
**             Prescaler               : divide-by-1
**             Clock                   : 2000000 Hz
**           Initial period/frequency
**             Xtal ticks              : 393216
**             microseconds            : 24576
**             milliseconds            : 25
**             seconds (real)          : 0.0245760
**             Hz                      : 41
**
**         Runtime setting             : none
**
**         Initialization:
**              Timer                  : Enabled
**              Events                 : Enabled
**
**         Timer registers
**              Counter                : TCNT      [68]
**              Mode                   : TIOS      [64]
**              Run                    : TSCR1     [70]
**              Prescaler              : TSCR2     [77]
**
**         Compare registers
**              Compare                : TC0       [80]
**
**         Flip-flop registers
**              Mode                   : TCTL2     [73]
**     Contents  :
**         No public methods
*/

/*                                                                     FOR TIMER 0
void I1_Enable(void)
{
  TIOS  = 1;        //output compare select..
  //OC7M=0;
  // TC0: BIT15=1,BIT14=1,BIT13=1,BIT12=1,BIT11=1,BIT10=1,BIT9=1,BIT8=1,BIT7=1,BIT6=1,BIT5=1,BIT4=1,BIT3=1,BIT2=1,BIT1=1,BIT0=1 
  TC0= 65535;                // Store given value to the compare register 
  
  TFLG1 = 1;                           // Reset interrupt request flag  
  TIE_C0I = 1;                         // Enable interrupt 
  TSCR1_TEN = 1;                       // Start timer  
}
*/

                                                                      // 7th TIMER
void TI1_Enable(void)
{
  TIOS  = 128;        //output compare select..
  /* TC0: BIT15=1,BIT14=1,BIT13=1,BIT12=1,BIT11=1,BIT10=1,BIT9=1,BIT8=1,BIT7=1,BIT6=1,BIT5=1,BIT4=1,BIT3=1,BIT2=1,BIT1=1,BIT0=1 */
  TC7= 65535;                /* Store given value to the compare register */ 
  TFLG1 = 128;                         /* Reset interrupt request flag */ 
  TIE_C7I = 1;                         /* Enable interrupt */ 
  TSCR1_TEN = 1;                       /* Start timer */   
}

void pulse_counter_init()
{
          //Pulse accumulator B
        PBCTL_PBEN=1;              //16 bit pulse accumulator enable bit (cascading two 8 bit pulse accumulator)
        
        TCTL4_EDG0B=1;        //configure the edge detector circuits
        TCTL4_EDG0A=0;        //10 is capture on falling edges only..
        
        DLYCT_DLY0=1;         //introduces delay of 1024 bus clock cycles..
        DLYCT_DLY1=1;
        PACN10=0;   //Sets the data register to 0.
}