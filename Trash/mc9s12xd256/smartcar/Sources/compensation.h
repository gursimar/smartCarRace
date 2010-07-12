/*Compensation ratio = 256.0 / (Black value – White value)*/

#define COM_RATIO_0 1.15
#define COM_RATIO_1  1.25
#define COM_RATIO_2   1.09
#define COM_RATIO_3    1.10
#define COM_RATIO_4      1.09
#define COM_RATIO_5     1.12
#define COM_RATIO_6      1.13
#define COM_RATIO_7       0

#define B_VAL_0    236
#define B_VAL_1    223
#define B_VAL_2     250
#define B_VAL_3     245
#define B_VAL_4     250
#define B_VAL_5     230
#define B_VAL_6      240
#define B_VAL_7       250

unsigned char compensate_value(unsigned char val,unsigned char sen_no)
{
	unsigned char temp;

	switch(sen_no)
	{
	      case 0:
	      {
	            temp = (val - B_VAL_0)*COM_RATIO_0;
	            break;
	      }
	      
	      case 1:
	      {
	            temp = (val - B_VAL_1)*COM_RATIO_1;
	            break;
	      }
	      
	      case 2:
	      {
	            temp = (val - B_VAL_2)*COM_RATIO_2;
	            break;
	      }
	      
	      case 3:
	      {
	            temp = (val - B_VAL_3)*COM_RATIO_3;
	            break;
	      }
	      
	      case 4:
	      {
	            temp = (val - B_VAL_4)*COM_RATIO_4;
	            break;
	      }
	      
	      case 5:
	      {
	            temp = (val - B_VAL_5)*COM_RATIO_5;
	            break;
	      }
	      
	      case 6:
	      {
	            temp = (val - B_VAL_6)*COM_RATIO_6;
	            break;
	      }
	      
	      case 7:
	      {
	            temp = (val - B_VAL_7)*COM_RATIO_7;
	            break;
	      }
	      
	      default :
	      {
	            ERRORLED=0;       //error led  on
	      }
	}
	
	return (unsigned char)temp;
}


