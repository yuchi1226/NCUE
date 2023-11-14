#include<stdio.h> 
#include<stdlib.h> 

int main()
{
	int a,b,p,sum=1,n=0,max=0,i;
	
	printf("please input the lower and upper:");
	scanf("%d %d",&a,&b);
	
	for(i=a;i<=b;i++)
	{
		p=i;
		
		while(p!=1)
		{	    
		
			sum=sum+p;
		
			if(p%2==0)			
				p=p/2;
		
			else if(p%2!=0)
			    p=3*p+1;
			
		}
		
		if(sum>max)
		{
			n=i;
			max=sum;
		}
		
		sum=1;
	}
	
	printf("n=%d sum=%d",n,max);
	
	
}
