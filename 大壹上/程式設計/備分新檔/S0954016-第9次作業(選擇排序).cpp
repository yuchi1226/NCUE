#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,m[6],j,h,max=0,count,k,temp;
	
	printf("請任意輸入 7 個數字:");
	for(i=0;i<7;i++)
	    scanf("%d",&m[i]);
	    
	for(j=0;j<7;j++)
	{
		max=0;
		
		for(h=j;h<7;h++)
		{
			if(m[h]>max)
			{
			   max=m[h];
		       count=h;
	    	}
	    }
		
		if(m[j]<max)
		{
			temp=m[j];
			m[j]=max;
			m[count]=temp;
			
			for(k=0;k<7;k++)
				printf("%d ",m[k]);
				    
			printf("\n");    
		}
	}    
}
