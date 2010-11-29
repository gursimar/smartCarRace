//Global definations
#define ON 1
#define OFF 0
#define LED_ON 0
#define LED_OFF 1

#define LED1 PTT_PTT4
#define LED2 PTT_PTT5
#define LED3 PTT_PTT6
#define LED4 PTT_PTT7

#define ADT_LED  LED1
#define BUTTON_LED  LED2

#define SW2  PTP_PTP5
#define SW3  PTP_PTP7

// EEPROMs VETOR ADDRESS
#define EEPROM_KP ((IEE1_TAddress)0x13F000)       //one byte
#define EEPROM_KI ((IEE1_TAddress)0x13F008)      
#define EEPROM_KD ((IEE1_TAddress)0x13F010)      
#define EEPROM_DELAYDC ((IEE1_TAddress)0x13F018)        //Need 1 byte address..
#define EEPROM_SETPOINT ((IEE1_TAddress)0x13F020)        //Need 1 byte address..

#define EEPROM_KP_DEFAULT                       8
#define EEPROM_KI_DEFAULT                       20
#define EEPROM_KD_DEFAULT                      8
#define EEPROM_DELAYDC_DEFAULT           3
#define EEPROM_SETPOINT_DEFAULT         1

// FLOAT POINT - EMULATION
#define DIV10000 10000
#define DIV1000 1000
#define DIV100 100

//Global Variables
unsigned char sen_data[7]=
{
15,
16,
60,
200,
50,
15,
15
};

// SWITCH interrupt CONTROL EEPROM VARIABLES. ...

unsigned char kp=0,ki=0,kd=0;
// kp(80,240)/1000       ki(20,100)/10000     kd(20,100)/10000
// kp(8,24)/100       ki(20,100)/10000     kd(2,10)/10000
unsigned char delay_dc=3;     //variable related to START_CROSS detection
unsigned char setpoint =1;    //set point is +ve and generally small values..   VAR RELATED TO PULSE counter
unsigned char dc_newval_flag=0;
unsigned int pulse_count=0;   //16 bit regsiter for accumulator


void Leds_and_Switches_Init()
{
          DDRT=0xF0;                // Setting Port T pin 4,5,6,7 as output
          
          DDRP_DDRP5=0;                 //Port P Pin 5 & 7 set to input 
          DDRP_DDRP7=0;        
          PERP_PERP5=1;                 //Port P Pin 5 & 7 Pullup Enable
          PERP_PERP7=1;

          LED1=LED_OFF;
          LED2=LED_OFF;
          LED3=LED_OFF;
          LED4=LED_OFF;

}


void Delay(unsigned char a) 
{
          unsigned int i,j;

          for(j=1;j<=a;j++)            //Delay
          for(i=0;i<=60000;i++);  
}