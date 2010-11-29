#ifndef _SENSOR_H
#define _SENSOR_H

#include "global.h"



/* Local Function Prototypes */
void Uncomp_Sensor_Value(int *ATD_ptr);
void Delay(unsigned char a);
void Switch_ON_LED(int LED);
bool Switch_Pressed(int SW);

#endif