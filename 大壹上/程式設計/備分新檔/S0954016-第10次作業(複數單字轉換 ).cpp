#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

int main()
{
	int  n,i;
	char word[20];
	
	printf("請輸入單數單字");
	scanf("%s",word);
	
	n=strlen(word)-1;
	int arr[26]={0};
	
	for(i=0;i<=n;i++)
	{
		arr[i]=word[i];
	} 
	
	if(arr[n]=='s' || arr[n]=='x' || arr[n]=='z' || (arr[n-1]=='c'&&arr[n]=='h') || (arr[n-1]=='s'&&arr[n]=='h'))
		printf("%ses",word);
	
	else if(arr[n]=='f')
	{
		word[n]='v';
		printf("%ses",word);
	}  
	
	else if(arr[n-1]=='f' && arr[n]=='e') 
	{
		word[n-1]='v';
		word[n]='e';
		printf("%ss",word);
	} 
	
	else if(arr[n]=='y')
	{
		if(!(arr[n-1]=='a' || arr[n-1]=='e' || arr[n-1]=='i' || arr[n-1]=='o' || arr[n-1]=='u'))
		{
			word[n]='i';
		    printf("%ses",word);
		}
		
		else
	        printf("%ss",word);
	}  

	else if(arr[n]=='o' && (arr[n-1]!='a' || arr[n-1]!='e' || arr[n-1]!='i' || arr[n-1]!='o' || arr[n-1]!='u'))
		printf("%ses",word);
	
	else
	    printf("%ss",word);
	
} 
