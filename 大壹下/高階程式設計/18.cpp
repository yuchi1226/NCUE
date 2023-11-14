#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include<stdio.h>
#include <string.h>
using namespace std;

int main()
{

char formation[101],//輸入的格式 
	string[101],//要判斷的字串 
	ch;//字元 
	

int num,i,j,k,len,lenth;

while(cin>>formation)
{	
	cin>>num;
	
	for(i=0;i<num;i++)
	{
		cin>>string;
		
		len=strlen(formation);
		int n=0,a1=0,a2=0,b1=0,b2=0,sum=0;
		char form[10][11]={0};//拆開 
		
		for(j=0;j<len;j++)
		{
			ch=formation[j];
			
			if(ch=='n' || ch==')'  )
			{
				n++;
				sum=0;
				continue;
			}	
			
			if(ch=='(' || ch=='*'  )				
				continue;
				
			if(n==0)	
				form[0][sum]= ch;
			else if(n==1)	
				form[1][sum]= ch;
			else if(n==2)	
				form[2][sum]= ch;
			else if(n==3)	
				form[3][sum]= ch;
				
			sum++;			
		}
		
		len=strlen(string);
		
		lenth=strlen(form[1]);
		for(j=0;j<len/2;j++)
		{
			if(string[j]==form[1][0])
			{
				for(k=1;k<lenth;k++)
				{
					if(string[j+k]!=form[1][k])
						break;
				}
				if(k>=lenth)
				{
					b1++;
					for(k=0;k<lenth;k++)
						string[j+k]=0;
				}
			}
			
		}//找 form[1]
		lenth=strlen(form[3]);
		for(j=len/2;j<len;j++)
		{
			if(string[j]==form[3][0])
			{
				for(k=1;k<lenth;k++)
				{
					if(string[j+k]!=form[3][k])
						break;
				}
				if(k>=lenth)
				{
					b2++;
					for(k=0;k<lenth;k++)
						string[j+k]=0;
				}
			}
			
		}//找 form[3] 
		
		for(j=0;j<len/2;j++)
		{
			if(string[j]==form[0][0]) 
				a1++;
			
		}//找 form[0]
		for(j=len/2;j<len;j++)
		{
			if(string[j]==form[2][0]) 
				a2++;
			
		}//找 form[2] 
		
		if(a1!=a2 || b1!=b2 || a1==0)	
			cout<<"N"<<endl;
		else
			cout<<"Y "<<a1<<" "<<b1<<endl;	
		
	}	
	
	
}
	
} 
