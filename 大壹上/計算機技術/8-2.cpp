#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

int main()
{
	int n1,count=0,n2,i,j,times=0;
	char str1[50],str2[50];
	
	printf("please input the string1:");
	scanf("%s%*c",&str1);
	
	printf("please input the string2:");
	scanf("%s%*c",&str2);
	
	n1=strlen(str1);
	n2=strlen(str2);
	
    for(i=0;i<=n1;i++)
    {
    	if(str1[i]==str2[0])
    	{
    		for(j=0;j<n2;j++)
    		{
    			if(str1[i+j]==str2[0+j])
    			   count ++;
    			   
    			else
    			   count=0;	  
			}
		
			if(count==n2)
		       times++; 
		 
		    
		}
		
		count=0;
	}
	
	
	if(times!=0)
	{
		printf("string2 is a substring of string1\n");
		printf("repeat %d times",times);
	}
	
	else
	    printf("string2 is not a substring of string1");
	
	
}
