#include <stdio.h> 
#include <stdlib.h> 

int main()
{
	int a,b,c,e,f;
	
	printf("please input a number: ");
	scanf("%d",&a);
	
	for(b=1;b<=a;b++)
	{
		for(c=1;c<=a-b;c++)
		{
			printf(" ");
		}
		
		for(e=1;e<=b;e++)
		{
			printf("%d",e%10);
		}
		
		for(f=b-1;f>=1;f--)
		{
			printf("%d",f%10);
		}
		
		printf("\n");
	}
}
