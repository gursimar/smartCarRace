// pid.c

#include "pid.h"
#include "sensorAnalyser.h"
#include "mc9s12xdt512.h"
#include "motor.h"
#include "global.h"

float Kp,Ki;
int error,p_ctrl,i_ctrl;
int output;
int error1;

//***************************************************************************************************


// Name: PID 
// Function: Performs the desired PI control to run motor
// Input: None
// Output: None

int PID(void){

            Kp=0.12;
           // Ki=0.005;

            error = Read_Sensor_Values();
    
            p_ctrl=(int)(error*Kp);
            i_ctrl=(int)((error + error1) * Ki) ;
            error1=error+error1;
            if (error1>32000){
              error1=32000 ;
            }
            if (error1<-32000){
              error1=-32000 ;
            }
            
            output= 1535 - p_ctrl;
            if (output>1800) {
              output = 1800;
            }
            if (output<1270){
              output = 1270;
            }
            return output;
        }
            
            
 //***************************************************************************************************


// Name: RUN 
// Function: Run the motor according to PI control
// Input: None
// Output: None  

void run(void){

            Servo_Motor();
            DC_Motor();
}

