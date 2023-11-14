#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int a,b,c,e,f,g,h,i,A=0,B,t=0;
	
	srand(time(NULL));
	a=rand()%10;
	b=rand()%10;
	c=rand()%10;
	e=rand()%10;
	
	while(b==a)
	   b=rand()%10;
	   
	while(c==a || c==b)
	   c=rand()%10;
	     
	while(e==a|| e==b|| e==c)
	   e=rand()%10;
	  
	  
	for(t=0;A!=4;t++)
	{
	
	printf("please input 4 digits(0~9): ");
	scanf("%1d%1d%1d%1d",&f,&g,&h,&i);
		
	if(f==a)
	  A++;
	  
	if(g==b)
	  A++;
	  
	if(h==c)
	  A++;      
	
	if(i==e)
	  A++;
	  
	if(f==b || f==c || f==e)
	  B++;
	  
	if(g==a || g==c || g==e)
	  B++;
	   
	if(h==a || h==b || h==e)
	  B++;
	  
	if(i==a || i==b || i==c )
	  B++;
	  
	if(A!=4)  
	{
	printf("the result is %dA%dB\n",A,B);
	
	A=0;
	B=0;  
	}
	
	}
	
	printf("you got it! %d times",t);
	  
}
