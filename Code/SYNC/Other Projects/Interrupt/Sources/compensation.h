/*Compensation ratio = 256.0 / (Black value – White value)*/

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


 
/**********************************************
Function - sort_array
Input - Two pointer to character arrays of size 8 and 3.
Output - Null
**********************************************/


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

