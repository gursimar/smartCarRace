/*Compensation ratio = 256.0 / (Black value – White value)*/

#define COM_RATIO_7      3.011
#define COM_RATIO_6      2.723
#define COM_RATIO_5      5.68
#define COM_RATIO_4      2.75
#define COM_RATIO_3      2.61
#define COM_RATIO_2      2.53
#define COM_RATIO_1      3.011
#define COM_RATIO_0      3.24

#define B_VAL_7     205
#define B_VAL_6     103
#define B_VAL_5     54
#define B_VAL_4     102
#define B_VAL_3      106
#define B_VAL_2     110
#define B_VAL_1      93
#define B_VAL_0       88

void compensate_value(unsigned char* val,unsigned char* com_val)
{
     *com_val = (*val - B_VAL_0)*COM_RATIO_0;
     *(com_val+1) = (*(val+1) - B_VAL_1)*COM_RATIO_1;
     *(com_val+2) = (*(val+2) - B_VAL_2)*COM_RATIO_2;
     *(com_val+3) = (*(val+3) - B_VAL_3)*COM_RATIO_3;
     *(com_val+4) = (*(val+4) - B_VAL_4)*COM_RATIO_4;
     *(com_val+5) = (*(val+5) - B_VAL_5)*COM_RATIO_5;
     *(com_val+6) = (*(val+6) - B_VAL_6)*COM_RATIO_6;
     *(com_val+7) = (*(val+7) - B_VAL_7)*COM_RATIO_7;
           
}

/**********************************************
Function - sort_array
Input - Two pointer to character arrays of size 8 and 3.
Output - Null
***********************************************/


void sort_array(unsigned char* a,unsigned char* b)
{  
     unsigned char i,j,temp;
     unsigned char c[3];
     
     c[0]=0;
     c[1]=0;
     c[2]=0;
     
	  for(i=0;i<3;i++)
     {
     		for(j=0;j<8;j++)
     		{
				if(c[i]<*(a+j))
     			{
     				c[i]=*(a+j);
     				b[i]=j;
     			}
     		}
   //  		printf("\nTEST %d %d\n",c[i],b[i]);
     		*(a+b[i])=0;
     }
     
      *(a+b[0])=c[0];
     	*(a+b[1])=c[1];
     	*(a+b[2])=c[2];
     
     
     for(i=0;i<8;i++)
     {
          for(j=i+1;j<8;j++)
          {
               if(*(a+i)<*(a+j))
               {
                   
                    temp=*(a+i);
                    *(a+i)=*(a+j);
                    *(a+j)=temp;
               }
          }
      }
      
      for(i=0;i<3;i++)
      {
          for(j=i;j<3;j++)
          {
               if(*(b+i)<*(b+j))
               {                   
                    temp=*(b+i);
                    *(b+i)=*(b+j);
                    *(b+j)=temp;
                    
                    temp=*(a+i);
                    *(a+i)=*(a+j);
                    *(a+j)=temp;
               }
          }
      }                               
}

