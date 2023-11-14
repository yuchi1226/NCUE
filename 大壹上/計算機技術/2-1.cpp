#include <stdlib.h>
#include <stdio.h>

int main()
{
	int a;
	
	printf("please input a positive integer : ");
	scanf("%d",&a);
	
	if(0>a)
	   {
	   printf("%d is not a positive integer.",a);
	   }
	   
	else if(1<a && a<9)
	   printf("%d is a small integer.",a);
	   
	else if(10<a && a<99)
	   {
	   printf("%d的十位數是%d\n",a,a/10);
	   printf("%d的個位數是%d",a,a%10);
	   } 
	   
	else if(100<a && a%5==0) 
	   {
	   	printf("%d is a large integer.\n",a);
	   	printf("%d is divisible by 5.",a);
	   }  
	   
	else if(100<a && a%5==1)
	   {
	   	printf("%d is a large integer.\n",a);
	   	printf("%d+5=%d.",a,a+5);
	   }
	
	else if(100<a && a%5==2)
	   {
	   	printf("%d is a large integer.\n",a);
	   	printf("%d-5=%d.",a,a-5);
	   }
	
	else if(100<a && a%5==3)
	   {
	   	printf("%d is a large integer.\n",a);
	   	printf("%d*5=%d.",a,a*5);
	   }
	
	else if(100<a && a%5==4)  
	   {
	   	printf("%d is a large integer.\n",a);
	   	printf("%d/5=%.2f.",a,(float)a/5);
	   }
	   	   
	return 0;   
}
