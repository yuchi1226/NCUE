#include<iostream> 
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main()
{
	int a,b,i,j,sum=0,max[10]={0},number[10],n,r;
	
	scanf("%d",&n);
	
	for(r=0;r<n;r++)
	{
		scanf("%d %d",&a,&b);
	    for(i=a;i<=b;i++)
	    {
		   j=i;
		   sum=1;
		
		   while(j!=1)
		   {
			  sum=sum+j;
			
			  if(j%2==0)
				  j=j/2;
				
			  else
			      j=3*j+1;	
		
		}
		
		   if(max[r]<sum)
		   {
			  max[r]=sum;
			  number[r]=i;
		   }
	    }
	
	}
	
	for(r=0;r<n;r++)
	    printf("%d %d\n",max[r],number[r]);

} 
