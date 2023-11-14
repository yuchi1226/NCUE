#include <stdio.h>
#include <stdlib.h>


int func1(int a,int b)
{
	int i,n;
	
	if(b>=a && a>=65 && a<=90 && b>=65 && b<=90)
	{
		for(i=a;i<=b;i++)
		   printf("%c",i);
		
		n=b-a+1;
		printf(" %d個",n);   
	}
	
	if(b>=a && a>=97 && a<=122 && b>=97 && b<=122)
	{
		for(i=a;i<=b;i++)
		   printf("%c",i);
		
		n=b-a+1;
		printf(" %d個",n);   
	}
	
	if(b>=a && a>=65 && a<=90 && b>=97 && b<=122)
	{
		for(i=a;i<=90;i++)
		   printf("%c",i);
		
		for(i=97;i<=b;i++)
		   printf("%c",i);
		   
		n=b-a-5;
		printf(" %d個",n);   
	}
	
	if(b<=a && a>=65 && a<=90 && b>=65 && b<=90)
	{
		for(i=a;i>=b;i--)
		   printf("%c",i);
		
		n=a-b;
		printf(" %d個",n);   
	}
	
	if(b<=a && a>=97 && a<=122 && b>=97 && b<=122)
	{
		for(i=a;i>=b;i--)
		   printf("%c",i);
		
		n=a-b;
		printf(" %d個",n);   
	}
	
	if(b<=a && a>=97 && a<=122 && b>=65 && b<=90)
	{
		for(i=a;i>=97;i--)
		   printf("%c",i);


		for(i=90;i>=b;i--)
		   printf("%c",i);
		   
		n=a-b-5;
		printf(" %d個",n);   
	}
	return n;
}

int main()
{
	char a,b;
	
	printf("輸入任意兩字母:");
	scanf("%c%c",&a,&b);
	
	func1(a,b);
}
