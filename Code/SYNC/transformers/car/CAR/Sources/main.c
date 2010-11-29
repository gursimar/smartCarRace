// MAIN.C

//include Files
#include <hidef.h>      
#include "derivative.h"      
#include "init.h"
#include "global.h"
#include "sensorAnalyser.h"
#include "TRIGGER_CAR.h"

void main(void) 
{
  
  bool start_car;    
  Bool sensor_calibrated = FALSE;
    
  initialisation();             //Initialisation
  
  // Wait until the calibration is done and Exit when the sensor is calibrated
  while(sensor_calibrated == FALSE){       
    sensor_calibrated = Calibrate_Sensors();   //Sensor Calibration
  }
  //Enable Interrupts
  start_car=sensor_calibrated;
   
  for(;;){

    TRIGGER_CAR(start_car);
  
  } 
}