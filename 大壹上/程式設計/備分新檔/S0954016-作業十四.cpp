#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
	char arr[10][20];
	char input[10],temp;
	int i,j,k=0;
	
	for(i=0;i<10;i++)	
	    for(j=0;j<10;j++)
	    {
	    	arr[i][j]='\0';
		}
	
	printf("輸入任意10個大寫小寫字母:");
	scanf("%s",input);
	
	for(i=0;i<10;i++)	
	    for(j=0;j<9;j++)
			if(input[j]>input[j+1])
			{
				temp=input[j];
				input[j]=input[j+1];
				input[j+1]=temp;	  
			} 
			
	for(i=0;i<5;i++)	
	    for(j=0;j<2;j++)
		{
			arr[i][j]=input[k];
			k++;
		}	
		
	for(i=0;i<10;i++)	
	{
		for(j=0;j<10;j++)
		{
			printf("%c",arr[i][j]);
		}	
		
		printf("\n");
	}
}
