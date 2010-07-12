/*Compensation ratio = 256.0 / (Black value – White value)*/

#define COM_RATIO_0
#define COM_RATIO_1
#define COM_RATIO_2
#define COM_RATIO_3
#define COM_RATIO_4
#define COM_RATIO_5
#define COM_RATIO_6
#define COM_RATIO_7

#define B_VAL_0
#define B_VAL_1
#define B_VAL_2
#define B_VAL_3
#define B_VAL_4
#define B_VAL_5
#define B_VAL_6
#define B_VAL_7

#include <stdint.h>

unsigned int8_t compensate_value(unsigned int8_t val,unsigned int8_t sen_no)
{
	float temp;
	temp = (val-B_VAL##sen_no)*COM_RATIO_##sen_no;
	return temp;
}


