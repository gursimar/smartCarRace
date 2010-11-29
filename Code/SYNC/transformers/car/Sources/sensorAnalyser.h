#ifndef _SENSORANALYSER_H
#define _SENSORANALYSER_H

#include "global.h"

/* Local Function Prototypes */

int Read_Sensor_Values(void);
void Comp_Sensor_Value(int *ATD_comp_ptr);
void Bubble_sort(void);
int Position_center(void);
bool Calibrate_Sensors(void);

#endif