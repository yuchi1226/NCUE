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
	
	printf("�п�J��ƪ��Ӽ�:");
	scanf("%d",&n);
	
	int arr[n];
	
	for(i=0;i<n;i++)
	{
		printf("�п�J��%d�Ӽ�:",i+1);
	    scanf("%d",&arr[i]);
	}
	
	sort(arr, n);
	
	printf("�Ƨǵ��G:");
	for(j=0;j<n;j++)
	   printf("%d ",arr[j]);
	   
}
