#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a,n,cou=1,A;
	
	printf("please input a number: ");
	scanf("%d",&n);
	
    printf("1"); 	
	
	for(a=2;cou<n;a++)
	{
		A=a;
		
	    while(A%2==0)
		  A=A/2;
			  
		while(A%3==0)
		  A=A/3;
			  
		while(A%5==0)
		  A=A/5;  
		  
		if(A==1)
		  {
		  	printf(",%d",a); 
		  	cou++;
		  } 
		
		
		
	}
}
