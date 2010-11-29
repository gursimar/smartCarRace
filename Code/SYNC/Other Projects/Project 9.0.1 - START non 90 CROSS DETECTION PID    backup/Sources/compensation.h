/*Compensation ratio = 256.0 / (Black value – White value)*/

float com_ratio[7]= 
{
1.75342,
2.0645,
2.39252,
2.3486,
2.4151,
2.0983,
1.9845
};

// MAX VALUES FOR w_val. SEPARATE w_val COMPUTATION ALGORITHM
unsigned char w_val[7]=
{
11,
10,
10,
10,
10,
10,
10
};

// MIN VALUES FOR b_val. SEPARATE b_val COMPUTATION ALGORITHM
unsigned char b_val[7] =
{
157,
134,
117,
119,
116,
132,
139
};

void compensate_value(unsigned char* val,unsigned char* com_val)
{         
          int i;
          for(i=0;i<6;i++)
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
                              // This will round off the value properly ....
                              *(com_val+i) = (unsigned char)(((*(val+i) - w_val[i]) * com_ratio[i]) + 0.5);
                     }
     
          }
         

}

 
/**********************************************
Function - sort_array
Input - One compensated array
Output - Null
***********************************************/


unsigned char sort_array(unsigned char* a)
{
          int i,index;
          index=0;
          for(i=1;i<7;i++)
          {
                    if(*(a+index) < *(a+i))
                    {
                              index=i;
                    }      
          }
          return index;
}