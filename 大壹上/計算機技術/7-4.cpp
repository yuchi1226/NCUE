#include<stdio.h> 
#include<stdlib.h> 

int main()
{
	int a,i,j,n,con=0;
	
	printf("please input a number:");
	scanf("%d",&a);
	
	for(i=2;i<=a;i++)
	{
		for(j=2;j<=i-1;j++)
		{
			if(i%j==0)	
	          break;
		}
		
		if(j<i-1)
		    n++;
	     
	    else
		    n=0;
		    
		if(n==4)
		{
			printf("(%d,%d,%d,%d)",i-3,i-2,i-1,i);
			con++;
			n=n-1;
		}
		
	}
	
	printf("\ntotal is %d",con);
}
