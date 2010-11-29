#define __DI()  { asm sei; }      /* Disable global interrupts  */
#define __EI()  { asm cli; }      /* Enable global interrupts */
#define ISR(x) __interrupt void x(void)

// variable assignments...
unsigned char sen_data[8]=
{
0,
0,
0,
0,
0,
0,
0,
0
};

/* float akps=0.11,skis=0.005;          //0.220
*/

unsigned char flag_sm=0;
char selection = -1;

void ISR_init()
{
          __EI()    //enable interrupts
          
            /* IRQCR: IRQEN=0 */
          IRQCR &= (unsigned char)~64;                     
 
          /* PIEP: PIEP7=1,PIEP6=0,PIEP5=1,PIEP4=0,PIEP3=0,PIEP2=0,PIEP1=0,PIEP0=0 */
          PIEP = 160;                                      
         
          //new code ends
}

ISR (isr_default)
{}

ISR (isrVatd0)
{
          //Clearing ASCIF is necessary as this will not cause reinitiating 
          //uart0_tx_newline();
          //uart0_tx_newline();
          //uart0_tx_newline();
          //uart0_tx_string(" :::: Interrupt ADC complete haha !! :::");
          //uart0_tx_newline();
          //uart0_tx_newline();
          //uart0_tx_newline();

          // See how many reads are req to clear the reg. It is conjectured that atleast one may req..
          
          //ADT_LED=~ADT_LED;
          
          //Actual code
          sen_data[0] =  ATD0DR0H;                //This will clear the Appropriate FLAG ..... 
          sen_data[1] =  ATD0DR1H;
          sen_data[2] =  ATD0DR2H;
          sen_data[3] =  ATD0DR3H;
          sen_data[4] =  ATD0DR4H;
          sen_data[5] =  ATD0DR5H;
          sen_data[6] =  ATD0DR6H;
          sen_data[7] =  ATD0DR7H;                                                                 
}


ISR (simar)
{  
          if(flag_sm!=0)
          {
                    //selection has been made
                    switch(selection)
                    {
                              case 0:
                              {
                                        union long_to_float simar_read;
                                        unsigned char return_val;

                                        if(PIFP&(1<<5))                             // (Active Low)  on Button 2 (PIN 5) has occured
                                        {
                                                  //uart0_tx_string(" Interrupt !! ... BUTTON 2  :::: ::::: ");    
                                                  //uart0_tx_newline();

                                                  // Clears flag. Writes logical one to the 5h          
                                                  //PIFP = 32;          
                                                  ki=ki+0.000250;
                                        }
                                        else
                                        {
                                                  //uart0_tx_string(" Interrupt !! ... BUTTON 3  :::: ::::: ");    
                                                  //uart0_tx_newline();
                                                  //PIFP = 128;                            // Clears flag. Writes logical one to the 7h          
                                                  ki=ki-0.000250;
                                        }

                                        //PIFP = 160;                            // Clears flag. Writes logical one to the 5h pin n 7th pin..          
                                        // This code writes the new value of KP to EEPROM
                                        simar_read.float_val = ki;
                                        return_val = IEE1_SetLong(EEPROM_KI,simar_read.long_val);
                                        if(return_val == ERR_OK) 
                                        {                      
                                                  LED1=LED_OFF;
                                                  Delay(2);
                                                  LED1=LED_ON;
                                        }          
                                        //ATD0CTL5_SCAN=0;
                                        break;
                              }

                              case 1:
                              {
                                        //kp is selected                                        
                                        union long_to_float simar_read;
                                        unsigned char return_val;

                                        if(PIFP&(1<<5))                             // (Active Low)  on Button 2 (PIN 5) has occured
                                        {
                                                  //uart0_tx_string(" Interrupt !! ... BUTTON 2  :::: ::::: ");    
                                                  //uart0_tx_newline();

                                                  // Clears flag. Writes logical one to the 5h          
                                                  //PIFP = 32;          
                                                  kp=kp+0.0025;
                                        }
                                        else
                                        {
                                                  //uart0_tx_string(" Interrupt !! ... BUTTON 3  :::: ::::: ");    
                                                  //uart0_tx_newline();
                                                  //PIFP = 128;                            // Clears flag. Writes logical one to the 7h          
                                                  kp=kp-0.0025;
                                        }

                                        //PIFP = 160;                            // Clears flag. Writes logical one to the 5h pin n 7th pin..          
                                        // This code writes the new value of KP to EEPROM
                                        simar_read.float_val = kp;
                                        return_val = IEE1_SetLong(EEPROM_KP,simar_read.long_val);
                                        if(return_val == ERR_OK) 
                                        {                      
                                                  LED2=LED_OFF;
                                                  Delay(2);
                                                  LED2=LED_ON;
                                        }          
                                        break;
                              }

                              case 2:
                              {
                                        // pulse accumulator set point
                                        break;
                              }

                              case 3:
                              {
                                        // QNAN EEPROM RESET
                                        if(PIFP&(1<<7))     //Button 3          //decrement
                                        {
                                                  EEPROM_reset();
                                        }
                                        break;
                              }
                              
                              case 4:
                              {
                                        //DELAY_DC
                                        if(PIFP&(1<<7))     //Button 3
                                        {
                                                  delay_dc--;
                                        }
                                        else
                                        {
                                                  delay_dc++;
                                        }
                                        
                                        break;
                              }
                              case 5:
                              {
                                        //UNUSED
                                        break;
                              }
                              case 6:
                              {
                                        //Auto compensation..
                                        break;
                              }
                              
                              
                    }
          }
          
          else
          {
                    if(PIFP&(1<<5))                             // (Active Low)  on Button 2 (PIN 5) has occured
                    {
                              
                              if(selection>=4)    //Rotating menu..
                              {
                                        selection=0;
                              }
                              else
                              {
                                        selection++;
                              }
                              
                              switch(selection)
                              {
                                        case 0:
                                        {
                                                  LED1=LED_ON;
                                                  LED2=LED_OFF;
                                                  LED3=LED_OFF;
                                                  LED4=LED_OFF;
                                                  break;
                                        }
                                        case 1:
                                        {
                                                  LED1=LED_OFF;
                                                  LED2=LED_ON;
                                                  LED3=LED_OFF;
                                                  LED4=LED_OFF;
                                                  break;
                                        }
                                        case 2:
                                        {
                                                  LED1=LED_OFF;
                                                  LED2=LED_OFF;
                                                  LED3=LED_ON;
                                                  LED4=LED_OFF;
                                                  break;
                                        }
                                        case 3:         //QNAN
                                        {
                                                  LED1=LED_OFF;
                                                  LED2=LED_OFF;
                                                  LED3=LED_OFF;
                                                  LED4=LED_ON;
                                                  break;
                                        }
                                        case 4:   //bounce back mechanism
                                        {
                                                  LED1=LED_OFF;
                                                  LED2=LED_OFF;
                                                  LED3=LED_ON;
                                                  LED4=LED_OFF;
                                                  break;
                                        }
                                        
                                        
                              }
                              
                    }
                    else
                    {
                              flag_sm=1;
                    }

                   
          }
          
          Delay(1);
          PIFP = 160;                            // Clears flag. Writes logical one to the 5h pin n 7th pin..          
          Delay(1);
          

}



/* Interrupt vector table */

/* ISR prototype */
typedef void (*near tIsrFunc)(void);

#ifndef UNASSIGNED_ISR
  #define UNASSIGNED_ISR isr_default   /* unassigned interrupt service routine */
#endif

const tIsrFunc _InterruptVectorTable[] @0xFF10 = { /* Interrupt vector table */
  /* ISR name                               No.  Address Pri XGATE Name          Description */
  UNASSIGNED_ISR,                       /* 0x08  0xFF10   -   -    ivVsi         unused by PE */
  UNASSIGNED_ISR,                       /* 0x09  0xFF12   1   no   ivReserved119 unused by PE */
  UNASSIGNED_ISR,                       /* 0x0A  0xFF14   1   no   ivReserved118 unused by PE */
  UNASSIGNED_ISR,                       /* 0x0B  0xFF16   1   no   ivReserved117 unused by PE */
  UNASSIGNED_ISR,                       /* 0x0C  0xFF18   1   no   ivReserved116 unused by PE */
  UNASSIGNED_ISR,                       /* 0x0D  0xFF1A   1   no   ivReserved115 unused by PE */
  UNASSIGNED_ISR,                       /* 0x0E  0xFF1C   1   no   ivReserved114 unused by PE */
  UNASSIGNED_ISR,                       /* 0x0F  0xFF1E   1   no   ivReserved113 unused by PE */
  UNASSIGNED_ISR,                       /* 0x10  0xFF20   1   no   ivReserved112 unused by PE */
  UNASSIGNED_ISR,                       /* 0x11  0xFF22   1   no   ivReserved111 unused by PE */
  UNASSIGNED_ISR,                       /* 0x12  0xFF24   1   no   ivReserved110 unused by PE */
  UNASSIGNED_ISR,                       /* 0x13  0xFF26   1   no   ivReserved109 unused by PE */
  UNASSIGNED_ISR,                       /* 0x14  0xFF28   1   no   ivReserved108 unused by PE */
  UNASSIGNED_ISR,                       /* 0x15  0xFF2A   1   no   ivReserved107 unused by PE */
  UNASSIGNED_ISR,                       /* 0x16  0xFF2C   1   no   ivReserved106 unused by PE */
  UNASSIGNED_ISR,                       /* 0x17  0xFF2E   1   no   ivReserved105 unused by PE */
  UNASSIGNED_ISR,                       /* 0x18  0xFF30   1   no   ivReserved104 unused by PE */
  UNASSIGNED_ISR,                       /* 0x19  0xFF32   1   no   ivReserved103 unused by PE */
  UNASSIGNED_ISR,                       /* 0x1A  0xFF34   1   no   ivReserved102 unused by PE */
  UNASSIGNED_ISR,                       /* 0x1B  0xFF36   1   no   ivReserved101 unused by PE */
  UNASSIGNED_ISR,                       /* 0x1C  0xFF38   1   no   ivReserved100 unused by PE */
  UNASSIGNED_ISR,                       /* 0x1D  0xFF3A   1   no   ivReserved99  unused by PE */
  UNASSIGNED_ISR,                       /* 0x1E  0xFF3C   1   no   ivReserved98  unused by PE */
  UNASSIGNED_ISR,                       /* 0x1F  0xFF3E   1   no   ivReserved97  unused by PE */
  UNASSIGNED_ISR,                       /* 0x20  0xFF40   1   no   ivReserved96  unused by PE */
  UNASSIGNED_ISR,                       /* 0x21  0xFF42   1   no   ivReserved95  unused by PE */
  UNASSIGNED_ISR,                       /* 0x22  0xFF44   1   no   ivReserved94  unused by PE */
  UNASSIGNED_ISR,                       /* 0x23  0xFF46   1   no   ivReserved93  unused by PE */
  UNASSIGNED_ISR,                       /* 0x24  0xFF48   1   no   ivReserved92  unused by PE */
  UNASSIGNED_ISR,                       /* 0x25  0xFF4A   1   no   ivReserved91  unused by PE */
  UNASSIGNED_ISR,                       /* 0x26  0xFF4C   1   no   ivReserved90  unused by PE */
  UNASSIGNED_ISR,                       /* 0x27  0xFF4E   1   no   ivReserved89  unused by PE */
  UNASSIGNED_ISR,                       /* 0x28  0xFF50   1   no   ivReserved88  unused by PE */
  UNASSIGNED_ISR,                       /* 0x29  0xFF52   1   no   ivReserved87  unused by PE */
  UNASSIGNED_ISR,                       /* 0x2A  0xFF54   1   no   ivReserved86  unused by PE */
  UNASSIGNED_ISR,                       /* 0x2B  0xFF56   1   no   ivReserved85  unused by PE */
  UNASSIGNED_ISR,                       /* 0x2C  0xFF58   1   no   ivReserved84  unused by PE */
  UNASSIGNED_ISR,                       /* 0x2D  0xFF5A   1   no   ivReserved83  unused by PE */
  UNASSIGNED_ISR,                       /* 0x2E  0xFF5C   1   no   ivReserved82  unused by PE */
  UNASSIGNED_ISR,                       /* 0x2F  0xFF5E   1   no   ivReserved81  unused by PE */
  UNASSIGNED_ISR,                       /* 0x30  0xFF60   1   -    ivVxsramav    unused by PE */
  UNASSIGNED_ISR,                       /* 0x31  0xFF62   1   -    ivVxsei       unused by PE */
  UNASSIGNED_ISR,                       /* 0x32  0xFF64   1   no   ivVxst7       unused by PE */
  UNASSIGNED_ISR,                       /* 0x33  0xFF66   1   no   ivVxst6       unused by PE */
  UNASSIGNED_ISR,                       /* 0x34  0xFF68   1   no   ivVxst5       unused by PE */
  UNASSIGNED_ISR,                       /* 0x35  0xFF6A   1   no   ivVxst4       unused by PE */
  UNASSIGNED_ISR,                       /* 0x36  0xFF6C   1   no   ivVxst3       unused by PE */
  UNASSIGNED_ISR,                       /* 0x37  0xFF6E   1   no   ivVxst2       unused by PE */
  UNASSIGNED_ISR,                       /* 0x38  0xFF70   1   no   ivVxst1       unused by PE */
  UNASSIGNED_ISR,                       /* 0x39  0xFF72   1   no   ivVxst0       unused by PE */
  UNASSIGNED_ISR,                       /* 0x3A  0xFF74   1   no   ivVpit3       unused by PE */
  UNASSIGNED_ISR,                       /* 0x3B  0xFF76   1   no   ivVpit2       unused by PE */
  UNASSIGNED_ISR,                       /* 0x3C  0xFF78   1   no   ivVpit1       unused by PE */
  UNASSIGNED_ISR,                       /* 0x3D  0xFF7A   1   no   ivVpit0       unused by PE */
  UNASSIGNED_ISR,                       /* 0x3E  0xFF7C   1   no   ivVReserved65 unused by PE */
  UNASSIGNED_ISR,                       /* 0x3F  0xFF7E   1   no   ivVapi        unused by PE */
  UNASSIGNED_ISR,                       /* 0x40  0xFF80   1   no   ivVlvi        unused by PE */
  UNASSIGNED_ISR,                       /* 0x41  0xFF82   1   no   ivVReserved62 unused by PE */
  UNASSIGNED_ISR,                       /* 0x42  0xFF84   1   no   ivVReserved61 unused by PE */
  UNASSIGNED_ISR,                       /* 0x43  0xFF86   1   no   ivVsci4       unused by PE */
  UNASSIGNED_ISR,                       /* 0x44  0xFF88   1   no   ivVReserved59 unused by PE */
  UNASSIGNED_ISR,                       /* 0x45  0xFF8A   1   no   ivVsci2       unused by PE */
  UNASSIGNED_ISR,                       /* 0x46  0xFF8C   1   no   ivVpwmesdn    unused by PE */
  simar,                                /* 0x47  0xFF8E   1   no   ivVportp      used by PE */
  UNASSIGNED_ISR,                       /* 0x48  0xFF90   1   no   ivVReserved55 unused by PE */
  UNASSIGNED_ISR,                       /* 0x49  0xFF92   1   no   ivVReserved54 unused by PE */
  UNASSIGNED_ISR,                       /* 0x4A  0xFF94   1   no   ivVReserved53 unused by PE */
  UNASSIGNED_ISR,                       /* 0x4B  0xFF96   1   no   ivVReserved52 unused by PE */
  UNASSIGNED_ISR,                       /* 0x4C  0xFF98   1   no   ivVReserved51 unused by PE */
  UNASSIGNED_ISR,                       /* 0x4D  0xFF9A   1   no   ivVReserved50 unused by PE */
  UNASSIGNED_ISR,                       /* 0x4E  0xFF9C   1   no   ivVReserved49 unused by PE */
  UNASSIGNED_ISR,                       /* 0x4F  0xFF9E   1   no   ivVReserved48 unused by PE */
  UNASSIGNED_ISR,                       /* 0x50  0xFFA0   1   no   ivVReserved47 unused by PE */
  UNASSIGNED_ISR,                       /* 0x51  0xFFA2   1   no   ivVReserved46 unused by PE */
  UNASSIGNED_ISR,                       /* 0x52  0xFFA4   1   no   ivVReserved45 unused by PE */
  UNASSIGNED_ISR,                       /* 0x53  0xFFA6   1   no   ivVReserved44 unused by PE */
  UNASSIGNED_ISR,                       /* 0x54  0xFFA8   1   no   ivVReserved43 unused by PE */
  UNASSIGNED_ISR,                       /* 0x55  0xFFAA   1   no   ivVReserved42 unused by PE */
  UNASSIGNED_ISR,                       /* 0x56  0xFFAC   1   no   ivVReserved41 unused by PE */
  UNASSIGNED_ISR,                       /* 0x57  0xFFAE   1   no   ivVReserved40 unused by PE */
  UNASSIGNED_ISR,                       /* 0x58  0xFFB0   1   no   ivVcan0tx     unused by PE */
  UNASSIGNED_ISR,                       /* 0x59  0xFFB2   1   no   ivVcan0rx     unused by PE */
  UNASSIGNED_ISR,                       /* 0x5A  0xFFB4   1   no   ivVcan0err    unused by PE */
  UNASSIGNED_ISR,                       /* 0x5B  0xFFB6   1   no   ivVcan0wkup   unused by PE */
  UNASSIGNED_ISR,                       /* 0x5C  0xFFB8   1   no   ivVflash      unused by PE */
  UNASSIGNED_ISR,                       /* 0x5D  0xFFBA   1   no   ivVeeprom     unused by PE */
  UNASSIGNED_ISR,                       /* 0x5E  0xFFBC   1   no   ivVspi2       unused by PE */
  UNASSIGNED_ISR,                       /* 0x5F  0xFFBE   1   no   ivVspi1       unused by PE */
  UNASSIGNED_ISR,                       /* 0x60  0xFFC0   1   no   ivViic0       unused by PE */
  UNASSIGNED_ISR,                       /* 0x61  0xFFC2   1   no   ivVReserved30 unused by PE */
  UNASSIGNED_ISR,                       /* 0x62  0xFFC4   1   no   ivVcrgscm     unused by PE */
  UNASSIGNED_ISR,                       /* 0x63  0xFFC6   1   no   ivVcrgplllck  unused by PE */
  UNASSIGNED_ISR,                       /* 0x64  0xFFC8   1   no   ivVtimpabovf  unused by PE */
  UNASSIGNED_ISR,                       /* 0x65  0xFFCA   1   no   ivVtimmdcu    unused by PE */
  UNASSIGNED_ISR,                       /* 0x66  0xFFCC   1   no   ivVporth      unused by PE */
  UNASSIGNED_ISR,                       /* 0x67  0xFFCE   1   no   ivVportj      unused by PE */
  UNASSIGNED_ISR,                       /* 0x68  0xFFD0   1   no   ivVatd1       unused by PE */
  isrVatd0,                             /* 0x69  0xFFD2   1   no   ivVatd0       used by PE */
  UNASSIGNED_ISR,                       /* 0x6A  0xFFD4   1   no   ivVsci1       unused by PE */
  UNASSIGNED_ISR,                       /* 0x6B  0xFFD6   1   no   ivVsci0       unused by PE */
  UNASSIGNED_ISR,                       /* 0x6C  0xFFD8   1   no   ivVspi0       unused by PE */
  UNASSIGNED_ISR,                       /* 0x6D  0xFFDA   1   no   ivVtimpaie    unused by PE */
  UNASSIGNED_ISR,                       /* 0x6E  0xFFDC   1   no   ivVtimpaaovf  unused by PE */
  UNASSIGNED_ISR,                       /* 0x6F  0xFFDE   1   no   ivVtimovf     unused by PE */
  UNASSIGNED_ISR,                       /* 0x70  0xFFE0   1   no   ivVtimch7     unused by PE */
  UNASSIGNED_ISR,                       /* 0x71  0xFFE2   1   no   ivVtimch6     unused by PE */
  UNASSIGNED_ISR,                       /* 0x72  0xFFE4   1   no   ivVtimch5     unused by PE */
  UNASSIGNED_ISR,                       /* 0x73  0xFFE6   1   no   ivVtimch4     unused by PE */
  UNASSIGNED_ISR,                       /* 0x74  0xFFE8   1   no   ivVtimch3     unused by PE */
  UNASSIGNED_ISR,                       /* 0x75  0xFFEA   1   no   ivVtimch2     unused by PE */
  UNASSIGNED_ISR,                       /* 0x76  0xFFEC   1   no   ivVtimch1     unused by PE */
  UNASSIGNED_ISR,                       /* 0x77  0xFFEE   1   no   ivVtimch0     unused by PE */
  UNASSIGNED_ISR,                       /* 0x78  0xFFF0   1   no   ivVrti        unused by PE */
  UNASSIGNED_ISR,                       /* 0x79  0xFFF2   1   no   ivVirq        unused by PE */
  UNASSIGNED_ISR,                       /* 0x7A  0xFFF4   -   -    ivVxirq       unused by PE */
  UNASSIGNED_ISR,                       /* 0x7B  0xFFF6   -   -    ivVswi        unused by PE */
  UNASSIGNED_ISR                        /* 0x7C  0xFFF8   -   -    ivVtrap       unused by PE */
};
