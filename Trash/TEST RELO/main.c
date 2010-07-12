#include <stdio.h>
#include <conio.h>

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

void showbits(unsigned char a)
{

	register char i;
	for(i=7;i>=0;i--)
	{
		a&(1<<i)?printf("1"):printf("0");
	}
	printf("\n");
}

void servo_set(int a)
{
	//	a should range somewhere in 1180 to 1820
	unsigned char PWMDTY2;
	unsigned char PWMDTY3;
	
	PWMDTY2 = (a>>8);
	a=a<<8;
	a=a>>8;                
	PWMDTY3 = a;
	showbits(PWMDTY2);
	showbits(PWMDTY3);
	
}

void main()
{
	unsigned char a[8]={6,100,100,255,68,100,87,254},b[3];
	register unsigned char i;
	
	sort_array(a,b);
	
	printf("\nTHESE VALUES OF a");
	for(i=0;i<8;i++)
	{
		printf(" %d   ",a[i]);
	}
	
	printf("\nTHESE VALUES OF b");
	for(i=0;i<3;i++)
	{
		printf(" %d   ",b[i]);
	}
	
	printf("\n");
	servo_set(1000);
	getch();	
}

