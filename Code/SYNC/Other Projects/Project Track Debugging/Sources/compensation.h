/*Compensation ratio = 256.0 / (Black value – White value)*/

/*
These values are taken by me and Mandy on white board track
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
*/

/*
#define COM_RATIO_7      3.506
#define COM_RATIO_6      1.1689
#define COM_RATIO_5      1.1926
#define COM_RATIO_4      1.1926
#define COM_RATIO_3      1.2549
#define COM_RATIO_2      1.1926
#define COM_RATIO_1       1.2549
#define COM_RATIO_0      1.1689

// These are infact white values
#define B_VAL_7    130
#define B_VAL_6    10
#define B_VAL_5     10
#define B_VAL_4    10
#define B_VAL_3     10
#define B_VAL_2    10
#define B_VAL_1     10
#define B_VAL_0    12
*/

float com_ratio[8]= 
{
1.3195,
1.61,
1.6842,
1.8285,
1.7181,
1.6516,
1.4301,
0
};

unsigned char w_val[8]=
{
12,
10,
10,
10,
11,
11,
11,
144       
};
unsigned char b_val[8] =
{
206,
169,
162,
150,
160,
166,
190,
198
};

void compensate_value(unsigned char* val,unsigned char* com_val)
{         
          int i;
          for(i=0;i<8;i++)
          {
                     if(*(val+i)<w_val[i])        //lower bound
                     {
                              *(com_val+i)=0;
                     }
                     
                     else if (*(val+i)> (b_val[i]))    //higher bound
                     {
                              *(com_val+i)=255;
                     }
                     else
                     {
                              *(com_val+i) = (*(val+i) - w_val[i]) * com_ratio[i];
                     }
     
          }
         

}

/*
void compensate_value(unsigned char* val,unsigned char* com_val)
{
     *com_val = (*val - B_VAL_0)*COM_RATIO_0;
     *(com_val+1) = (*(val+1) - B_VAL_1)*COM_RATIO_1;
     *(com_val+2) = (*(val+2) - B_VAL_2)*COM_RATIO_2;
     *(com_val+3) = (*(val+3) - B_VAL_3)*COM_RATIO_3;
     *(com_val+4) = (*(val+4) - B_VAL_4)*COM_RATIO_4;
     *(com_val+5) = (*(val+5) - B_VAL_5)*COM_RATIO_5;
     *(com_val+6) = (*(val+6) - B_VAL_6)*COM_RATIO_6;
     // This is done because it has high values, can be daelt later in code development
     *(com_val+7) =0; // (*(val+7) - B_VAL_7)*COM_RATIO_7;
           
}
 */
 
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

