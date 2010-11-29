#ifndef _GLOBAL_H   
#define _GLOBAL_H
   
   
#include <mc9s12xdt512.h>
#include "stdtypes.h"

#define bool        Bool
#define SINT8       sint

//General definition
#define ON           0
#define OUTPUT       1
#define ENABLE       1
#define OFF          1
#define INPUT        0
#define DISABLE      0
#define HIGH         1
#define LOW          0
#define RESET        0x00
#define NONE         0

//hardware based defined values
#define SA_DC        5
#define SB_DC        5
#define PER_DC1      200
#define PER_DC2      200
#define PER_SERVO1   0x4E
#define PER_SERVO2   0x20
#define EXT_TRIG_OFF 0x87
#define EXT_TRG_ON   0x03
#define MUL_SEQ      0x10 
#define SA_SERVO     1
#define SB_SERVO     1
#define BYTES        8
#define DTY2_CENTER  5
#define DTY3_CENTER  135
#define DTY0_FORW    75
#define DTY1_FORW    0

#define PORT_T_AS_OUTPUT  0xF0
#define LED1_ON      0xEF
#define LED2_ON      0xDF
#define LED3_ON      0xBF
#define ALLLED_OFF   0xFF


//Sensor related
#define LED1         0
#define LED2         1
#define LED3         2
#define LED4         3
#define LED5         4
#define LED6         5
#define LED7         6
#define LED8         7
#define TOTAL_LEDS   7 
#define SW2          2
#define SW3          3
#define VALUE_DIFF   50
#define SENSOR_RESET 0x10
#define ASST_SENSORS 2
#define MAX_CAL      256
#define MAX_CAL_SNS_VALUE 512
#define Scaling_factor 100
#define HEX         16

   
#endif