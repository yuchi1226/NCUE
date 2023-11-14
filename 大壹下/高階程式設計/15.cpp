#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include<stdio.h>
#include <string>
using namespace std;

int main()
{
	int cla,num;//班級數和幾筆資料 
	int i,j,k;
	
	
while(cin>>cla>>num)
{
	int a[5000][2];//資料存入 
	long long int b[5000][5000];
	int count=0;//有幾班 
	int sum[5000]={0};//此班的人數 
	
	for(i=0;i<num;i++)
		for(j=0;j<2;j++)
			scanf("%d",&a[i][j]);
		
for(i=0;i<num;i++)
{
	bool found=false;
	
	for(j=0;j<count;j++)//第j班 
	{
		if(found==true) break;
		
		for(k=0;k<sum[j];k++)//第j班的第k人 
		{
			if(a[i][0]==b[j][k])//發現此班有同學在 
			{
				b[j][k+1]=a[i][1];
				sum[j]++;//新增此人到這間教室 
				found=true;
				break;
			}
				 
			else if(a[i][1]==b[j][k])//發現此班有同學在 
			{
				b[j][k+1]=a[i][0];
				sum[j]++;//新增此人到這間教室
				found=true;
				break;
			} 
		}
    }
			
	if(found==false)//沒找到同學 
	{
		count++;
		
		b[j][sum[j]]=a[i][0];//將資料存入新的一班 
		sum[j]++;
		
		b[j][sum[j]]=a[i][1];
		sum[j]++;
		
	}	
		
}
	
	

if(count>num)	
	printf("%d\n",num);
else
	printf("%d\n",count);			
	
}//while end

}
