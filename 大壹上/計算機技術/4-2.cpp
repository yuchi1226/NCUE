#include <stdio.h> 
#include <stdlib.h> 

int main()
{
	int a,i,j,n=0;
	
	printf("please input a number: ");
	scanf("%d",&a);
	
	for(i=2;i<=a;i++)
	{
		for(j=2;j<=i-1;j++)
	    {

	       if(i%j==0)	
	          break;
	    }
	
	    if(j>i-1)
	     {
		    printf("%d,",j);
		    n++;
	     }
	}
	
	printf("\ntotal is %d ",n);
}
