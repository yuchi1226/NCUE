#include <stdlib.h>
#include <stdio.h>

void sort(int *arr,int n)
{
	int i,j,temp,k;
	
	
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(*(arr+j)>*(arr+j+1))
			{
				temp=*(arr+j);
				*(arr+j)=*(arr+j+1);
				*(arr+j+1)=temp;
			}
		}
	}
}

int main()
{
	int n,i,j;
	
	printf("請輸入整數的個數:");
	scanf("%d",&n);
	
	int arr[n];
	
	for(i=0;i<n;i++)
	{
		printf("請輸入第%d個數:",i+1);
	    scanf("%d",&arr[i]);
	}
	
	sort(arr, n);
	
	printf("排序結果:");
	for(j=0;j<n;j++)
	   printf("%d ",arr[j]);
	   
}
