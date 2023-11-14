#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b=2,c,e,sum=0,count=0,max,min;

	printf("Please input the number of integers:");
	scanf("%d",&a);
	
	printf("integer#1:");
	scanf("%d",&c);
	
	max=c;
	min=c;
	
	sum=sum+c;	
	
    while(b<=a)
	  {
		printf("integer#%d:",b);
		scanf("%d",&e);
		
		sum=sum+e;
		count++;
        b++;
	
	    if(c<=e)
	      max=e;
	      
	    if(e<=c)
	      min=e;  
	
	  }
	  
	printf("The average is %.2f\n ",(float)sum/a);
	printf("The max is %d\n",max);
	printf("The min is %d",min);
}
