#include <stdio.h>
#include <stdlib.h>
#include<string.h> 

void check_10(char *arr,int n)
{
	
	
	int m0,m1,m2,m3,m4,m5,m6,m7,m8,m9,sum; 
		 
	m0=arr[0]-'0';
	m1=arr[1]-'0';
	m2=arr[2]-'0';
	m3=arr[3]-'0';
	m4=arr[4]-'0';
	m5=arr[5]-'0';
	m6=arr[6]-'0';
	m7=arr[7]-'0';
	m8=arr[8]-'0';
		
	if(arr[9]=='x')
		m9=10;
	else
		m9=arr[9]-'0';
		  
	sum=m0*10+m1*9+m2*8+m3*7+m4*6+m5*5+m6*4+m7*3+m8*2+m9*1;
		
	if(sum%11==0)
		printf("the ISBN code is correct!!!\n");
	else
		printf("the ISBN code is wrong!!!\n");   
}

void check_13(char *arr,int n)	
{
	int m0,m1,m2,m3,m4,m5,m6,m7,m8,m9,m10,m11,m12,sum; 
		
	m0=arr[0]-'0';
	m1=arr[1]-'0';
	m2=arr[2]-'0';
	m3=arr[3]-'0';
	m4=arr[4]-'0';
	m5=arr[5]-'0';
	m6=arr[6]-'0';
	m7=arr[7]-'0';
	m8=arr[8]-'0';
	m9=arr[9]-'0';
	m10=arr[10]-'0';
	m11=arr[11]-'0';
	m12=arr[12]-'0';
		
	sum=m0*1+m1*3+m2*1+m3*3+m4*1+m5*3+m6*1+m7*3+m8*1+m9*3+m10*1+m11*3;
		
	if(10-(sum%10)==m12 || (sum%10)==0)
		printf("the ISBN code is correct!!!\n");
	else
		printf("the ISBN code is wrong!!!\n");   

}

int main()
{
	int n,arr[12];
	char code[14];
	
	
	do{
		printf("please intput an ISBN code:");
	    scanf("%s",code);
	
	    n=strlen(code);
	    
	    if(n==10)
	      check_10(code,n);
	    if(n==13)  
	      check_13(code,n);
	    
	}while(n==10 || n==13);
	
	printf("error!!");
	
}
