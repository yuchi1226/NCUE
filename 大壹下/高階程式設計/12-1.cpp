#include <iostream>
#include <iomanip>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
	
char string[100000];
while(scanf("%s",string))
{
	int i,j,len,max=0,total=0,sum=0;
	int lenth[10000]={0};//�������� 
	int arr[10000]={0},brr[10000]={0};//�����r���Y�� 
	
	len=strlen(string);
	
	for(i=0;len-i>=max && i<len ;i++)//�����I������� //��֮ɶ�:1.��Ѿl��r�֩�max�ɴN���� 
	{
		if(string[i-1]==string[i+1]) //1.���-->������
		{
			for(j=1;;j++)
			{
				if(i-1-j<0 || i+1+j>len || string[i-1-j]!=string[i+1+j])
				    break;
			}
				
			if(2*j+1>=max)
			{
				arr[total]=i-j;
				brr[total]=i+j;
				max=brr[total]-arr[total]+1;
				lenth[total]=max;
				total++;
			}
		}
		
		else if(string[i-1]==string[i])//�P�e�@�� 
		{
			for(j=1;i-1-j<0;j++)
			{
				if(i-1-j<0 || i+j>len || string[i-1-j]!=string[i+j])
				    break;
			}
			
			if(2*j+1>=max)
			{
				arr[i]=i-j;
				brr[i]=i+j-1;
				max=brr[i]-arr[i]+1;
				lenth[i]=max;
				total++;
			}
		}
		else if(string[i]==string[i+1])//�P��@�� 
		{
			for(j=1;;j++)
			{
				if(i-j<0 || i+1+j>len || string[i-j]!=string[i+1+j])
				    break;
			}
			
			if(2*j+1>=max)
			{
				arr[total]=i-j+1;
				brr[total]=i+j;
				max=brr[total]-arr[total]+1;
				lenth[total]=max;
				total++;
			}
		}
		
	}//���̫�@�r
	
	
	
	if(max==0)	
		printf("0");
	else
	{
		printf("%d ",max);
	
	    for(i=0;i<total;i++)
		    if(lenth[i]==max)
		    {
		    	if(sum==0)
		    	{   
				    for(j=arr[i];j<=brr[i];j++)
				        printf("%c",string[j]);
		    	    sum=1; 
		    	}    
		    	else
				{
					printf(", ");
					for(j=arr[i];j<=brr[i];j++)
				        printf("%c",string[j]);
				}   
			       
		    }
	    
	}
		
		printf("\n"); 
}
}
