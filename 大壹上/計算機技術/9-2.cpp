#include <stdlib.h>
#include <stdio.h>
#include<string.h> 

int fact(int n)
{
	int i,j=1;
	
	if(n==1 || n==0)
	   return 1;
	
	for(i=2;i<=n;i++)
	   j=j*i;
	   
	return j;   
	
}

int main()
{
	int n,i,sum1=1,sum2=1,j,k;
	long long int per=0;
	int letter[25]={0};
	int number[10]={0};
	char str1[13];
	
	printf("please input a string:");
	scanf("%s",str1);

    n=strlen(str1);

    for(i=0;i<=n;i++)
    {
    	if((int)str1[i]>=65 && (int)str1[i]<=90) 
    	   {
    	   	letter[str1[i]-'A']++;
		   }
    	   
    	if((int)str1[i]>=97 && (int)str1[i]<=122) 
    	   { 
			letter[str1[i]-'a']++ ;
		   } 
		   
		number[str1[i]-'0']++;   
    	   
	}
	
	for(j=0;j<=25;j++)
	    sum1=sum1*fact(letter[j]);
	    
    for(k=0;k<=10;k++)
	    sum2=sum2*fact(number[k]);

    per=fact(n)/(sum1*sum2);
    
    printf("the number of permutations is %d",per);
    
} 
