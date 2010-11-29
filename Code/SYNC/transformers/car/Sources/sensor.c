
// file: sensor.c

// Initializes the hardware and software and calibrate the sensors


#include "mc9s12xdt512.h"
#include "sensor.h"
#include "global.h"

 
//Global variables
int ATD_arr[BYTES];


//***************************************************************************************************


// Name: Switch_ON_LED
// Function: switch on the desired LED
// Input: LED number
// Output: NULL

void Switch_ON_LED(int LED){
    switch(LED) {
        case LED1:    PTT_PTT4=ON;               //LED 1 On
                      break;
        
        case LED2:    PTT_PTT5=ON;               //LED 2 On
                      break;
        
        case LED3:    PTT_PTT6=ON;               //LED 3 On
                      break;
        
        case LED4:    PTT_PTT7=ON;               //LED 4 On
                      break;
    }
}


//***************************************************************************************************


// Name: Switch_ON_LED
// Function: switch on the desired LED
// Input: LED number
// Output: NULL

bool Switch_Pressed(int SW){
    
    int result = FALSE;
    
    switch(SW){
      case SW2: if(PTP_PTP5 == ON){           //Check for if SW2 is pressed
                    result = TRUE;
                }
                break;
                
      case SW3: if(PTP_PTP7 == ON){           //Check for if SW3 is pressed
                    result = TRUE;
                }
                break;
                
      default:  break;
    }
    return result;
}


//***************************************************************************************************


// Name: Uncomp_Sensor_Value 
// Function: Read the sensors value from the ATD pins
// Input: NULL
// Output: Pointer to the ATD sensor values

void Uncomp_Sensor_Value(int *ATD_ptr) {
        
        ATD0CTL5=SENSOR_RESET;        // Reset the sensor values
        Delay(ENABLE);
       
        *ATD_ptr  = ATD0DR0H;        //Reads the current value available at the pin: ATD0
        *(ATD_ptr+1)= ATD0DR1H;
        *(ATD_ptr+2)= ATD0DR2H;
        *(ATD_ptr+3)= ATD0DR3H;
        *(ATD_ptr+4)= ATD0DR4H;
        *(ATD_ptr+5)= ATD0DR5H;
        *(ATD_ptr+6)= ATD0DR6H;
        *(ATD_ptr+7)= ATD0DR7H;
}


//***************************************************************************************************


// Name: Delay 
// Function: 
// Input: Delay in milliseconds
// Output: NULL

void Delay(unsigned char time) {
        unsigned int count1,count2;

        for(count2=1;count2<=time;count2++){
          //Delay
          for(count1=0;count1<=1000;count1++){
          }
        }
}     