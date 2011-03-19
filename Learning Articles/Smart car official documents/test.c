#include <hidef.h>      
#include "derivative.h"      

void uart0_9600_init(void);
unsigned char uart0_rx(void);
void uart0_tx(unsigned char a);
void uart0_tx_string(char *s) ;
void uart0_tx_number(unsigned char a);
void Delay(unsigned char a);
void uart0_tx_newline(void);
void display_menu(void);
void uart0_tx_int(unsigned int a);


void main(void) 
{
unsigned int flag1,flag2;
unsigned long cnt;
char ans;

uart0_9600_init();

//Display Menu
//uart0_tx(0x0C);
display_menu();

for(;;) 
  {
  
ans=uart0_rx();


if(ans=='1')        //LED Test
     {
         DDRT=0xF0;                // Setting Port T pin 4,5,6,7 as output
         PTT=0x0F;                 // Turning on all LEDs 
         uart0_tx_string("LEDs On:   All    ");
         
         Delay(12);
         
         PTT=0xFF;                 //Turning Off all LEDs
        
         Delay(2); 
              
         PTT_PTT4=0;               //LED 1 On
         uart0_tx(0x0D);
         uart0_tx_string("LEDs On:   LED 1    ");
             
         Delay(5); 
              
         PTT_PTT5=0;               //LED 2 On
         PTT_PTT4=1;
         uart0_tx(0x0D);
         uart0_tx_string("LEDs On:   LED 2    ");
            
         Delay(5);
               
         PTT_PTT6=0;               //LED 3 On
         PTT_PTT5=1;
         uart0_tx(0x0D);
         uart0_tx_string("LEDs On:   LED 3    ");
            
         Delay(5); 
              
         PTT_PTT7=0;               //LED 4 On
         PTT_PTT6=1;
         uart0_tx(0x0D);
         uart0_tx_string("LEDs On:   LED 4    ");
         
         Delay(5); 
        
         PTT_PTT7=1; 
         
         uart0_tx(0x0D);
         uart0_tx_string("LED Test Completed");
         uart0_tx_newline();
         display_menu();
         
    }else if(ans=='2') 
    {   
    
        //switch test
        
        DDRP_DDRP5=0;                 //Port P Pin 5 & 7 set to input 
        DDRP_DDRP7=0;
        
        PERP_PERP5=1;                 //Port P Pin 5 & 7 Pullup Enable
        PERP_PERP7=1;
        
        flag1=0;
        flag2=0;
        
        uart0_tx_string("Press switch1 : ");
                                        
        for (cnt=0;cnt<=550000;cnt++) 
              {
              if(PTP_PTP5==0)          // checking Port P Pin 5 : Switch 1 
                {
                uart0_tx_string("SW1 Pressed      ");
                flag1=1;
                break;
                }
              }
        if(flag1==0) {
            uart0_tx_string("Switch1 not Pressed ");
            }
       
        uart0_tx_newline();
        uart0_tx_string("Press switch2 : ");
        
        for (cnt=0;cnt<=550000;cnt++) 
              {
              if(PTP_PTP7==0)         // checking Port P Pin 7 : Switch 2 
                {
                uart0_tx_string("SW2 Pressed      ");
                flag2=1;
                break;
                }
              }
        
        if(flag2==0) {
            uart0_tx_string("Switch2 not Pressed ");
            }      
        
       
        uart0_tx_newline();
        uart0_tx_string("Switch test completed.");
        uart0_tx_newline();
        display_menu();
    
    }else if(ans=='3') 
    {
        //DC motor Test
  
        
        
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
        
        PWMDTY0 = 30;                
        PWMDTY1 = 0;
        
        PWME_PWME0=1;                //PWM channel 0 Enable
        PWME_PWME1=1;                //PWM channel 1 Enable
        
       
        uart0_tx_string("Motor started. : forward Direction    ");
        
        Delay(10);
        
        PORTE_PE3=0;
        PWMDTY0 = 0;                
        PWMDTY1 = 30;
        // Reverse Direction

        Delay(5);
        PORTE_PE3=1;
        
        uart0_tx_string("Reverse Direction");
        
        Delay(10);
        
        // Stop Motor
        PORTE_PE3=0;
        
        PTP_PTP0=0;
        PTP_PTP1=0;
        PWME_PWME0=0;                //PWM channel disable
        PWME_PWME1=0;
        
        uart0_tx_newline();
        uart0_tx_string("Motor Test completed");
        uart0_tx_newline();
        display_menu();
        
    
    }else if(ans=='4') {
        //servo motor test
       
        PWMCTL_CON23=1;
        
        PWME_PWME2=1;                //PWM channel 2 Enable
        PWME_PWME3=1;                //PWM channel 3 Enable
        
        PWMPOL_PPOL2=1;              //PWM pulse High at begining of Period
        PWMPOL_PPOL3=1;              //PWM pulse High at begining of Period
        
        PWMCLK_PCLK2=1;              // clock SA as clock source for PWM
        PWMCLK_PCLK3=1;              // clock SB as clock source for PWM
        
            
        PWMPRCLK =0x00;              //clock A = 2MHz  clockB = 2MHz
        
        PWMSCLA =1;                //clock  SA = clock A / (2 * 100) = 10KHz
        PWMSCLB =1;                //clock  SB = clock B / (2 * 100) = 10KHz
    
        PWMPER2 = 0x4E;               // PWM Period 20ms           50Hz
        PWMPER3 = 0x20;               // PWM Period 20ms           50Hz
        
        PWMDTY2 = 0x05;                // Pulse Width 1.5ms: Center Position
        PWMDTY3 = 0x87;                //1.415ms
        
        uart0_tx_string("Servo Motor Position: Center   ");
        
        Delay(10);
          
          
        PWMDTY2 = 0x04;                //Pulse Width: Left Position
        PWMDTY3 = 0x6A;                //1.1ms
        uart0_tx_string("Left   ");
        
        Delay(10);
        
        
        PWMDTY2 = 0x06;                //Pulse Width 1.7 ms: Right Position
        PWMDTY3 = 0xA4;
        uart0_tx_string("Right   ");
        
        Delay(10);
          
        PWMDTY2 = 0x05;                // Pulse Width: Center Position
        PWMDTY3 = 0x87;                //1.415ms
        uart0_tx_string("Center   ");
        uart0_tx_newline();
        
        Delay(10);
        
        PWME_PWME2=0;                //Stoping PWM
        PWME_PWME3=0;
        
        uart0_tx_string("Servo Test completed..");
        uart0_tx_newline();
        display_menu();
    
    
    }else if(ans=='5'){
        
        //Read ATD values
        
        ATD0CTL1=0x87;                    // no external trigger
        ATD0CTL2_ADPU=1;                  // ATD Enable
        ATD0CTL2_ETRIGE=0;                // no external trigger
        ATD0CTL3_S8C=1;                   // 8 adc channels sequence
        ATD0CTL4_SRES8=1;                 // 8-bit Resolution
        ATD0CTL5=0x10;                    // multisequence
        
        uart0_tx_string("ATD values are (AN7 -> AN0):  ");
        
        Delay(1);                         //Delay
        
        uart0_tx_number(ATD0DR7H);        //Analog value channel 7
        uart0_tx_string("   ");
        uart0_tx_number(ATD0DR6H);        //Analog value channel 6
        uart0_tx_string("   ");
        uart0_tx_number(ATD0DR5H);        //Analog value channel 5
        uart0_tx_string("   ");
        uart0_tx_number(ATD0DR4H);        //Analog value channel 4
        uart0_tx_string("   ");
        uart0_tx_number(ATD0DR3H);        //Analog value channel 3
        uart0_tx_string("   ");
        uart0_tx_number(ATD0DR2H);        //Analog value channel 2
        uart0_tx_string("   ");
        uart0_tx_number(ATD0DR1H);        //Analog value channel 1
        uart0_tx_string("   ");
        uart0_tx_number(ATD0DR0H);        //Analog value channel 0
        uart0_tx_newline();
        display_menu();
    }else if(ans=='6'){
        
        DDRE_DDRE2=1;              // Port E pin 2 & 3 set to output
        DDRE_DDRE3=1;
        
        PORTE_PE2=0;               //H-bridge enable 
        PORTE_PE3=1;

        
        PBCTL_PBEN=1;              //pulse counter init
        TCTL4_EDG0B=1;
        TCTL4_EDG0A=0;
        DLYCT_DLY0=1;
        DLYCT_DLY1=1;
        PACN10=0;
       
        
        PWMPOL_PPOL0=1;              //PWM pulse High at begining of Period
        PWMPOL_PPOL1=1;              //PWM pulse High at begining of Period
        
        PWMCLK_PCLK0=1;              // clock SA as clock source for PWM
        PWMCLK_PCLK1=1;              // clock SB as clock source for PWM
        
            
        PWMPRCLK =0x00;              //clock A = 2MHz  clockB = 2MHz
        
        PWMSCLA =5;                //clock  SA = clock A / (2 * 1) = 1000KHz
        PWMSCLB =5;                //clock  SB = clock B / (2 * 1) = 1000KHz
    
        PWMPER0 = 200;               // PWM Period           1KHz
        PWMPER1 = 200;               // PWM Period           1KHz
        
        PWMDTY0 = 30;                
        PWMDTY1 = 0;
        
        PWME_PWME0=1;                //PWM channel enable
        PWME_PWME1=1;

        
        //start motor
        
        uart0_tx_string("Pulse counter is running: Press any key to see number of rotation");
        ans=uart0_rx();
        
        PORTE_PE2=1;                 //disable motor
        PORTE_PE3=0;
        
        PWME_PWME0=0;                
        PWME_PWME1=0;                
        
        uart0_tx_newline();
        uart0_tx_string("Number of rotation of wheel is :  ");
        
        uart0_tx_int(PACN10/8);
        uart0_tx_newline();
        PACN10=0;
        PBCTL_PBEN=0;
        uart0_tx_newline();
        display_menu();  
    
    
    }
  }


}


void display_menu(void) {


uart0_tx_newline();
uart0_tx_string("============================================================");
uart0_tx_newline();
uart0_tx_string("           Board test: Enter following number");
uart0_tx_newline(); 
uart0_tx_string("1:To Test LEDs");
uart0_tx_newline();
uart0_tx_string("2:To Test Switch");
uart0_tx_newline();
uart0_tx_string("3:To Test DC Motor");
uart0_tx_newline();
uart0_tx_string("4:To Test Servo Motor");
uart0_tx_newline();
uart0_tx_string("5:To Check Analog to Digital values");
uart0_tx_newline();
uart0_tx_string("6:To check Pulse counter value");
uart0_tx_newline();
uart0_tx_string("============================================================");
uart0_tx_newline();

}

void Delay(unsigned char a) {
unsigned int i,j;

for(j=1;j<=a;j++)            //Delay
     for(i=0;i<=60000;i++);

}

//UART functions..... 
void uart0_9600_init(void) {
  SCI0BDL=13;
  SCI0CR1=0;
  SCI0CR2=12; 
}


void uart0_tx_int(unsigned int a) {
unsigned int temp;

temp=a/10000;
uart0_tx(temp + 0x30);
a=a-temp*10000;

temp=a/1000;
uart0_tx(temp + 0x30);
a=a-temp*1000;

temp=a/100;
uart0_tx(temp + 0x30);
a=a-temp*100;

temp=a/10;
uart0_tx(temp + 0x30);
a=a-temp*10;

uart0_tx(a + 0x30);
}


void uart0_tx_number(unsigned char a) {
unsigned char temp;
temp=a/100;
uart0_tx(temp + 0x30);
a=a-temp*100;
temp=a/10;
uart0_tx(temp + 0x30);
a=a-temp*10;
uart0_tx(a + 0x30);
}

void uart0_tx_string(char *s) {

	while (*s) 
	{
		uart0_tx(*s);
		s++;
	}
}

void uart0_tx_newline(void) { 
uart0_tx(0x0A);
uart0_tx(0x0D);
}

unsigned char uart0_rx(void) {
  while(SCI0SR1_RDRF==0);
  return SCI0DRL;
}


void uart0_tx(unsigned char a) {
  SCI0DRL=a;
  while(SCI0SR1_TC==0);
}