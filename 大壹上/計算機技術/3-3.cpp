#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a,b,c,e;
	
	printf("please input a number:");
	scanf("%d",&a);
	
	for(e=1;e<=a;e++)
	{
		for(b=a-e;b>=1;b--)
		{
			printf(" ");			
		}
		
		for(c=1;c<=2*e-1;c+=1)
		{
			printf("%d",e%10);				
		}

		printf("\n");
	}

}
