#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 

int main()
{
	int n,i;
	
	scanf("%d",&n);
	printf("%d=",n);
	
	for(i=2;i<=n;i++)
	{
		while(n!=i)
		{
			if(n%i==0)
			{
				printf("%d*",i);
			    n=n/i;
				
			}
			
			else 
			    break;
				   
		}
	}
	
	printf("%d",n);
}
