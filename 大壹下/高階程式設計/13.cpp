#include <iostream>
#include <iomanip>
#include<stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

int main()
{
	int num,i,j,m;
	
while(cin>>num)//��J�n���X�� 
{
	int a,arr[50]={0},brr[50]={0};
	int maxsum=0,minsum=0,recordmax,recordmin;
	
	for(m=0;m<num;m++)
	{
		int a,arr[50]={0},brr[50]={0};
	    int maxsum=0,minsum=0,recordmax,recordmin;
		
		cin>>a;//�o�@�����X�ӼƦr 
		for(j=0;j<a;j++)
		{
			cin>>arr[j];
			brr[j]=arr[j];
		}
		
	int count=0;		
	while(count<a-2)//��̤j 
	{
		int max=0;
		
		for(i=1;i<=a-2-count;i++)//v�M��ثe���̤j
		{
			if(arr[i]>max)
			{
				max=arr[i];
				recordmax=i;
		    }
		    
		} 
		
		maxsum+=arr[recordmax-1]*arr[recordmax]*arr[recordmax+1];
		
		for(j=recordmax;j<a-1-count;j++)//��̤j���c�� 
		{
			arr[j]=arr[j+1];
		}
		
		arr[j]=0;
		count++;
		
	}
	
	count=0;
	while(count<a-2)//��̤p 
	{
		int min=1000;
		
		for(i=1;i<=a-2-count;i++)//�M��ثe���̤p 
		{
		    if(brr[i]<min)
		    {
		    	min=brr[i];
				recordmin=i;
			}
		} 
		
		minsum+=brr[recordmin-1]*brr[recordmin]*brr[recordmin+1];
		
		for(j=recordmin;j<a-count;j++)//��̤p���c��
		{
			brr[j]=brr[j+1];
		}
		
		brr[j]=0;
		count++;
		
	}
	
	if(maxsum>minsum) 
	    printf("%d %d\n",maxsum,minsum);
	else 
	    printf("%d %d\n",minsum,maxsum);
	
	}
}
}
