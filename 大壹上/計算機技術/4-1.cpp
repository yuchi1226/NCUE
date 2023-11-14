#include <stdio.h> 
#include <stdlib.h> 

int main()
{
	int p1=0,p2=1,item,a,i;
	
	printf("please input a number: ");
	scanf("%d",&a);
	
	printf("0,1");
	
	for(i=3;i<=a;i++)
	{   
	item=p1+p2;
	
	printf(",%d",item);  
	
	p1=p2;
	p2=item;	    			
	}
	
	
	
	
	
}
