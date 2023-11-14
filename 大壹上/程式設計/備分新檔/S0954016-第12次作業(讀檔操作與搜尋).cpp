#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 



int main()
{
	int arr[20],brr[20],low,high,left,right,mid;
	int a=1,b=1,n,i,j,input;
	
	
	FILE *Data1;
    FILE *Data2;
    FILE *Data3;
    Data1=fopen("作業十二附檔_1.txt","r+");
    Data2=fopen("作業十二附檔_2.txt","r+");
    Data3=fopen("作業十二輸出.txt","w");
	
if(Data1!=NULL && Data2!=NULL)
{
	while(fscanf(Data1,"%d,",&input)==1)
    {
    	arr[a]=input;
    	a++;
	}
	
	while(fscanf(Data2,"%d,",&input)==1)
    {
    	brr[b]=input;
    	b++;
	}
	
	printf("搜尋：");
	scanf("%d",&n);
	
	low=1;
    high=a;
    
	while(low<=high)
	{
		mid = (low + high) / 2;
		
		if(n==arr[mid])
		{
			printf("存在於數列中");
			break;
		}
		
		else if (arr[mid] > n)
        {
            high = mid - 1;
        }
        else if (arr[mid] < n)
        {
            low = mid + 1;
        }
	}
	left=1;
	right=b;  
	if(low>high)
	{
		while(left<=right)
	    {
		    mid = (left + right) / 2;
		
		    if(n==brr[mid])
		    {
			    printf("存在於數列中");
			    break;
		    }
		
		    else if (brr[mid] > n)
            {
                right = mid - 1;
            }
            else if (brr[mid] < n)
            {
                left = mid + 1;
            }
	    }
	}
	if(left>right)
	   printf("不存在於數列中"); 
	

} 
    fclose(Data1);
	fclose(Data2);
	fclose(Data3);

} 
