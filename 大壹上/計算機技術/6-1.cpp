#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,i,j,h;
	
	printf("please input the size of martrix:");
	scanf("%d",&n);
	
	int m1[n][n],m2[n][n],p1=0;
	
	printf("please input matrix1:");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&m1[i][j]);
		}
	}
	
	printf("please input matrix2:");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&m2[i][j]);
		}
	}

	printf("matrix1*matrix2=\n");
	
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(h=0;h<n;h++)
			{
				p1=p1+m1[i][h]*m2[h][j];
			}
			printf("%d ",p1);
			p1=0;
		}
		printf("\n");				
		
	}
	
}
