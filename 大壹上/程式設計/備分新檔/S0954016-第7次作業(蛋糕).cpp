#include <iostream>
#include<stdio.h> 
#include<stdlib.h> 

int main()
{
	int n,k,c,i,m[i],j,sum=0,max=0;
	
	printf("請輸入N K\n");
	scanf("%d %d",&n,&k);
	
	printf("請輸入蛋糕的評分\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&m[i]);
	}
	
	for(j=0;j<=n-k;j++)
	{	
	    sum=0;
		
		for(i=j;i<k+j;i++)
		{			
			sum=sum+m[i];
				
			if(sum>max)
			   max=sum;						
		}
				
	}
	
	printf("%d",max); 
}
