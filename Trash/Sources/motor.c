// file: motor.c

// Initializes the hardware and software and calibrate the sensors


#include "mc9s12xdt512.h"
#include "motor.h"
#include "global.h"
#include "pid.h"

//*************************************************************************************************
// Name: Servo_Motor 
// Function: Align the Servo motor
// Input: NULL
// Output: NULL

void Servo_Motor(void) {
   
   int dty2,dty3,servo;
   
   servo= PID();
   dty2= servo>>8;
   servo= servo & 0x00FF;
   dty3=servo;
   PWMDTY2 = dty2;                // Pulse Width 1.5ms: Center Positionign
   PWMDTY3 = dty3;                //1.415ms
      
}
      
//*************************************************************************************************
// Name: DC_Motor 
// Function: Run the DC motor straight
// Input: NULL
// Output: NULL

void DC_Motor(void) {

    PORTE_PE3=ENABLE;

    PWMDTY0 = DTY0_FORW ;                   // Setting Duty Cycle-0 to 30 fo DC Motor 
    PWMDTY1 = DTY1_FORW ;                    // Setting Duty Cycle-1 to 0 
        
    PWME_PWME0=ENABLE;                //PWM channel 0 Enable
    PWME_PWME1=ENABLE;                //PWM channel 1 Enable
        
}

