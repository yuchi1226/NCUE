#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

int main()
{
	int n1,n2,d,u=0,i,j;
	int code[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	char str1[50],str2[50];
	
	n1=strlen(str1);
	printf("please input string #1:");
	scanf("%[^\n]%*c",str1);

    for(i=0;i<n1-1;i++)
    {
    	if((int)str1[i]>=65 && (int)str1[i]<=90) 
    	   {
    	   	code[str1[i]-'A']+=1;
		   }
    	   
    	if((int)str1[i]>=97 && (int)str1[i]<=122) 
    	   { 
			code[str1[i]-'a']+=1 ;
		   } 
    	   
	}
    
    n2=strlen(str2);
    printf("please input string #2:");
	scanf("%[^\n]%*c",str2);

    for(j=0;j<n2-1;j++)
    {
    	if((int)str1[j]>=65 && (int)str1[j]<=90) 
    	   {
    	   	code[str2[j]-'A']-=1;
		   }
    	   
    	if((int)str1[j]>=97 && (int)str1[j]<=122) 
    	   { 
    	   	code[str2[j]-'a']-=1;
		   } 
    	   
	}

    for(i=0;i<=25;i++)
    {
	   if(code[i]!=0)
	     u=1;
	}
    
	if(u==0)
	   printf("yes");   
       
    else
	   printf("no");   

}
