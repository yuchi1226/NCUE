#include<stdio.h>
#include<stdlib.h>

int main()
{
	int arr[20]={0},a,b,c;
	
	FILE *Data1;
    FILE *Data2;
    Data1=fopen("�@�~�Q�G����_1.txt","r+");
    Data2=fopen("�@�~�Q�G��X.txt","wb");
    
	while(fscanf(Data1,"%d,",&arr[a])==1)
    	a++;
	
	fwrite( arr, sizeof(int), a, Data2);

    fclose(Data1);
	fclose(Data2);

    printf("�j�M:");
    scanf("%d",&b);
    
    Data2=fopen("�@�~�Q�G��X.txt","rb");
	fread(arr,sizeof(int),a,Data1);
	     for(c=0;c<a;c++)
	        printf("%2d",arr[c]);
	        
	fclose(Data2);
	
	f(arr,b,c-1,0);        
}
