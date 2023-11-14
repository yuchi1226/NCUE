#include<stdio.h> 
#include<stdlib.h> 

int main()
{
	int i,m[8],max=0,min=0,c;
	
	printf("請輸入一個為 9 位數的數字:");
	for(i=0;i<9;i++)
	{
		min=max;
		
		scanf("%1d",&m[i]);
		
		if(m[i]>max)
		  max=m[i];
		  
	
	}
	
	c=100*m[6]+10*m[7]+m[8];
	
	if(max*max+min*min==c)
       printf("Good Morning!\n");
       
    else
	   printf("SPY!\n");   
	   
	system("pause");     
       
       
} 
