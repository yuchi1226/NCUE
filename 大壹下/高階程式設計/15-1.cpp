#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include<stdio.h>
#include <string>
using namespace std;

int sort(int *arr,int temp)
{
	if(arr[temp]==temp)
		return temp;
	else
	{
		arr[temp] = sort(arr, arr[temp]);
		return arr[temp];
	}
		
	
}

int main()
{
	int cla,num;//班級數和幾筆資料 
	
while(cin>>cla>>num)
{
	int arr[cla];//資料存入 
	int i,a,b;
	int count=0;//有幾班 
	
	for(i=0;i<cla;i++)//最多一人一班 
		arr[i] = i;
	
	for(i=0;i<num;i++)
	{
		cin>>a>>b;
		
		a=sort(arr, a);
		b=sort(arr, b);
			
		if(a!=b)
			arr[b]=a;
	}
		
	
	for(i=0;i<cla;i++)
		if(arr[i]==i)
			count++;	

	printf("%d\n",count);		
	
}//while end


} 


