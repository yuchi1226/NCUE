#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

int main()
{
	int a,b,arr[20],n=0,i,j;
	char ch,ch2;
	
	FILE *Data1;
	FILE *Data2;
	FILE *Data3;
	Data1=fopen("Hello.txt","r");
	Data2=fopen("11-1.txt","w+");
	Data3=fopen("11-1-2.txt","w");
	
	printf("¿é¤J¥[±K¼Æ¦r");
	scanf("%d",&a); 
	
	if(Data1!=NULL && Data2!=NULL)
	{
		while((ch=fgetc(Data1))!=EOF)
		{
			arr[n]=ch+a;
			n++;
			  
		}
		
		for(b=0;b<n;b++)
		    fprintf(Data2,"%c",arr[b]);
		
	}
	
	if( Data3!=NULL)
	{
		for(i=0;i<n;i++)
			arr[i]=arr[i]-a;
				
		for(j=0;j<n;j++)
		    fprintf(Data3,"%c",arr[j]);
		
	}
	
	fclose(Data1);
	fclose(Data2);
	fclose(Data3);

	

}
