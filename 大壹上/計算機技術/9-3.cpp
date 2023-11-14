#include <stdlib.h>
#include <stdio.h>

int main()
{
	int n,sum=0,i,j,k,count=0,m[100000];
	
	printf("please input a number:");
	scanf("%d",&n);
	
	for(i=2;i<=n;i++)
	{
		for(j=1;j<i;j++)
		{
			if(i%j==0)
			  sum=sum+j;
		}
		
		if(sum==i)
		  {
			m[count]=i;
			count++;
		  }
		  
		sum=0;
		
	}
	
	for(k=0;k<count;k++)
	   {
	    	printf("%d,",m[k]);
	   } 
	   
	printf("\n");   
	printf("there are %d perfect numbers!!",count);
	
	
} 
