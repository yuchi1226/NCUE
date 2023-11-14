#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<math.h> 

int main()
{
	int len,i,j,a,b,c,count=0;
	
	printf("please input a number:");
	scanf("%d",&j);
	
	for(i=1;i<=j;i++)
	{
		if(10<i && i<99)
		{
			a=i/10;
			b=i%10;
			c=a+b;
			
			if(c*c==i)
			{
				printf("%d,",i);
				count++;
			}  
			
		}
		  
		else if(1000<i && i<9999)
		{
			a=i/100;
			b=i%100;
			c=a+b;
			
			if(c*c==i)
			{
				printf("%d,",i);
				count++;
			}  
		}
		
		else if(100000<i && i<999999)
		{
			a=i/1000;
			b=i%1000;
			c=a+b;
			
			if(c*c==i)
			{
				printf("%d,",i);
				count++;
			}  
		}
		
		else
		   continue;  
	}
	
	printf("total is %d",count);
}
