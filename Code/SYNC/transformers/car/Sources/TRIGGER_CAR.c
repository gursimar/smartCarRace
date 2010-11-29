
// TRIGGER_CAR.c

#include "TRIGGER_CAR.h"
#include "sensorAnalyser.h"
#include "mc9s12xdt512.h"
#include "global.h"
#include "pid.h"




int ATD_cmp_arr[BYTES];


//***************************************************************************************************


// Name: TRIGGER_CAR 
// Function: Runs the car after completion of initialization and calibration
// Input: start_IRQ
// Output: Error

void TRIGGER_CAR(bool start_car){
         
    if(start_car == TRUE){
      
              run();
       
    }  
}
