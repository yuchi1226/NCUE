#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int a,i,j,length;
char A[2000]={0},B[2000]={0};

int main()
{
	scanf("%d",&a);
	
	int distance[a];
	
    for(i=0;i<a;i++)
        distance[i]=0;
	
	for(i=0;i<a;i++)
	{
		scanf("%s %s",A,B);
		
		length=strlen(A);
		
		for(j=0;j<length;j++)
		{
			if((int)(A[j]-B[j])<0) 
			   distance[i]=distance[i]+(int)(A[j]-B[j])*-1;
			   
			else
			   distance[i]=distance[i]+(int)(A[j]-B[j]);   
		}	
			
	
	}	
	
	for(i=0;i<a;i++)	
	   printf("%d\n",distance[i]);
	
}
