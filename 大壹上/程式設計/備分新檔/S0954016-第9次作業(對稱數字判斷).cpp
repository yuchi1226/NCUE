#include <stdio.h>
#include <stdlib.h>
#include<string.h> 

int main()
{
	int n,i,count=0,j;
	char code[20];
	
	printf("��J�@��D�t���:");
	scanf("%s",code);
	
	n=strlen(code);
	
	int number[20]={0};
	
	for(j=0;j<=n;j++)  	
		number[j]=code[j]-'0';
	
	for(i=0;i<=(n/2);i++)
	{
		if(number[i]==number[n-1-i])
		  count++;
		
		else if(n==1)
		  printf("���");
		  
		else
		  break;      
	}
	
	if(count==(n/2)+1)
	   printf("���");
	   
	else
	   printf("�����");    

}
