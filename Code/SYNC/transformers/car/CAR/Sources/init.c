// file: init.c

// Initializes the hardware and software and calibrate the sensors


#include "mc9s12xdt512.h"
#include "init.h"
#include "global.h"


void initialisation(void){
        
        A_D_init();                   // Sensor Initialisation
        Servo_Motor_init();           //Servo Motor Initialisation
        DC_Motor_init();              // DC Motor Initialisation
        Switch_n_LED_init();
        
}

//***************************************************************************************************
// Name: A_D_init 
// Function: Initialising the Sensors for Analog to Digital conversion on ATD `Channel 0
// Input: NULL
// Output: NULL

void A_D_init(void){
        
        
        ATD0CTL1=EXT_TRIG_OFF;                    // no external trigger
        ATD0CTL2_ADPU=ENABLE;                  // ATD Enable
        ATD0CTL2_ETRIGE=DISABLE;                // no external trigger
        ATD0CTL3_S8C=ENABLE;                   // 8 adc channels sequence
        ATD0CTL4_SRES8=ENABLE;                 // 8-bit Resolution 
        ATD0CTL5=MUL_SEQ;                    // multisequence      
}

//***************************************************************************************************
  // Name: Servo_Motor_init 
  // Function: Initialising the Servo motor, defining the clock period ()
  // Input: NULL
  // Output: NULL

void Servo_Motor_init(void) {
  
        
        PWMCTL_CON23=ENABLE;
        
        PWME_PWME2=ENABLE;                //PWM channel 2 Enable
        PWME_PWME3=ENABLE;                //PWM channel 3 Enable
        
        PWMPOL_PPOL2=HIGH;              //PWM pulse High at begining of Period
        PWMPOL_PPOL3=HIGH;              //PWM pulse High at begining of Period
        
        PWMCLK_PCLK2=ENABLE;              // clock SA as clock source for PWM
        PWMCLK_PCLK3=ENABLE;              // clock SB as clock source for PWM
        
            
        PWMPRCLK =RESET;              //clock A = 2MHz  clockB = 2MHz
        
        PWMSCLA =SA_SERVO;                //clock  SA = clock A / (2 * 100) = 10KHz     //Issue is here
        PWMSCLB =SB_SERVO;                //clock  SB = clock B / (2 * 100) = 10KHz
            
       
        PWMPER2 = PER_SERVO1 ;               // PWM Period 20ms           50Hz
        PWMPER3 = PER_SERVO2 ;               // PWM Period 20ms           50Hz
        
        
}

//*************************************************************************************************
// Name: DC_Motor_init 
// Function: Initialising the DC motor, defining the clock period ()
// Input: NULL
// Output: NULL

void DC_Motor_init(void) {
  
        DDRE_DDRE2=OUTPUT;              // Port E pin 2 & 3 set to output
        DDRE_DDRE3=OUTPUT;
        DDRP_DDRP0=OUTPUT;
        DDRP_DDRP1=OUTPUT;

        PORTE_PE2=DISABLE;                
        PORTE_PE3=ENABLE;
        
        PWMPOL_PPOL0=HIGH;              //PWM pulse High at begining of Period
        PWMPOL_PPOL1=HIGH;              //PWM pulse High at begining of Period
        
        PWMCLK_PCLK0=ENABLE;              // clock SA as clock source for PWM
        PWMCLK_PCLK1=ENABLE;              // clock SB as clock source for PWM
        
        PWMPRCLK =RESET;              //clock A = 2MHz  clockB = 2MHz
        
        PWMSCLA =SA_SERVO;                //clock  SA = clock A / (2 * 5) = 200KHz
        PWMSCLB =SB_SERVO;                //clock  SB = clock B / (2 * 5) = 200KHz
    
        PWMPER0 = PER_DC1;               // PWM Period           1KHz
        PWMPER1 = PER_DC2;               // PWM Period           1KHz
}

//*********************************************************************************************************
// Name: Switch_n_LED_init 
// Function: Initialise the Switch SW2 and SW3 and LEDs.
// Enable Port P as i/p for switch and Port T as o/p for LEDs
// Input: NULL
// Output: NULL



void Switch_n_LED_init(void) {
  
   DDRP_DDRP5=INPUT;                 //Port P Pin 5 & 7 set to input 
   DDRP_DDRP7=INPUT;
        
   PERP_PERP5=ENABLE;                 //Port P Pin 5 & 7 Pullup Enable
   PERP_PERP7=ENABLE;
        
   DDRT=PORT_T_AS_OUTPUT;               // Setting Port T pin 4,5,6,7 as output
   PTT=ALLLED_OFF;                 //Turning Off all LEDs
}        

