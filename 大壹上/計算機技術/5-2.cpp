#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a,i,j,n=0,p1,p2,h,k;
	
	printf("please input a number: ");
	scanf("%d",&a);
	
	for(i=2;i<=a;i++)
	{
		for(j=2;j<=i-1;j++)
	    {

	       if(i%j==0)	
	          break;
	    }
	
	    if(j>i-1)
	    {
		    p1=j;
		    h=p1+2;
		    
		    for(k=2;k<=h-1;k++)
	        {
                if(h%k==0)	
	            break;
	        }
	
	        if(k>h-1)
	        {
		        p2=k;
		       
		        printf("(%d,%d)",p1,p2);
		        n++;
	        }
	         
	    }
	     
	    
	}
	
	printf("\ntotal is %d ",n);
}

