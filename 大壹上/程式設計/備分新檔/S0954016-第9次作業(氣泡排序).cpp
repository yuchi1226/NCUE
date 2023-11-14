#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,m[6],j=0,k,temp,h;
	
	printf("請任意輸入 7 個數字:");
	for(i=0;i<7;i++)
	    scanf("%d",&m[i]);
	
	
	for(h=0;h<7;h++)	
	{
	    for(j=0;j<=5;j++)
		{
			if(m[j]<m[j+1])
			{
				temp=m[j];
				m[j]=m[j+1];
				m[j+1]=temp;
				
				for(k=0;k<7;k++)
				    printf("%d ",m[k]);
				    
				printf("\n");    
			} 
			
		}  	
	
	}
	
	
}
