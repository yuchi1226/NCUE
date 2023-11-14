#include<stdio.h>
#include<stdlib.h>

int main()
{
	int arr[20]={0},a,b,c;
	
	FILE *Data1;
    FILE *Data2;
    Data1=fopen("作業十二附檔_1.txt","r+");
    Data2=fopen("作業十二輸出.txt","wb");
    
	while(fscanf(Data1,"%d,",&arr[a])==1)
    	a++;
	
	fwrite( arr, sizeof(int), a, Data2);

    fclose(Data1);
	fclose(Data2);

    printf("搜尋:");
    scanf("%d",&b);
    
    Data2=fopen("作業十二輸出.txt","rb");
	fread(arr,sizeof(int),a,Data1);
	     for(c=0;c<a;c++)
	        printf("%2d",arr[c]);
	        
	fclose(Data2);
	
	f(arr,b,c-1,0);        
}
