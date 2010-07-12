/*Compensation ratio = 256.0 / (Black value – White value)*/

#define COM_RATIO_7      3.16
#define COM_RATIO_6      1.3689
#define COM_RATIO_5      1.5802
#define COM_RATIO_4      1.5609
#define COM_RATIO_3      1.5609
#define COM_RATIO_2      1.5058
#define COM_RATIO_1      1.641
#define COM_RATIO_0      1.4712

#define B_VAL_7    139
#define B_VAL_6    10
#define B_VAL_5     9
#define B_VAL_4     9
#define B_VAL_3     9
#define B_VAL_2    10
#define B_VAL_1     9
#define B_VAL_0    10

int compensate_value(unsigned char val,unsigned char sen_no)
{
	int temp;

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
	
	return (int)temp;
}


