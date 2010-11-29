//Global definations
#define ON 1;
#define OFF 0;
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
#define EEPROM_KP ((IEE1_TAddress)0x13F000)
#define EEPROM_KI ((IEE1_TAddress)0x13F010)      // 2 byte above
#define EEPROM_KD ((IEE1_TAddress)0x13F020)      // 2 byte above
#define EEPROM_DELAYDC ((IEE1_TAddress)0x13F030)        //Need 1 byte address..
#define EEPROM_SETPOINT ((IEE1_TAddress)0x13F038)        //Need 1 byte address..

//Global Variables
union long_to_float 
{
          unsigned long long_val;
          float float_val; 
};

unsigned char START=1;        //Variable that starts the car..

// SWITCH interrupt CONTROL EEPROM VARIABLES. ...
float kp=0.0,ki=0.0,kd=0.0;
unsigned char delay_dc=3;     //variable related to START_CROSS detection
unsigned char setpoint =1;    //set point is +ve and generally small values..   VAR RELATED TO PULSE counter


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