#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include<stdio.h>
#include <string>
using namespace std;

int main()
{
	int cla,num;//�Z�żƩM�X����� 
	int i,j,k;
	
	
while(cin>>cla>>num)
{
	int a[5000][2];//��Ʀs�J 
	long long int b[5000][5000];
	int count=0;//���X�Z 
	int sum[5000]={0};//���Z���H�� 
	
	for(i=0;i<num;i++)
		for(j=0;j<2;j++)
			scanf("%d",&a[i][j]);
		
for(i=0;i<num;i++)
{
	bool found=false;
	
	for(j=0;j<count;j++)//��j�Z 
	{
		if(found==true) break;
		
		for(k=0;k<sum[j];k++)//��j�Z����k�H 
		{
			if(a[i][0]==b[j][k])//�o�{���Z���P�Ǧb 
			{
				b[j][k+1]=a[i][1];
				sum[j]++;//�s�W���H��o���Ы� 
				found=true;
				break;
			}
				 
			else if(a[i][1]==b[j][k])//�o�{���Z���P�Ǧb 
			{
				b[j][k+1]=a[i][0];
				sum[j]++;//�s�W���H��o���Ы�
				found=true;
				break;
			} 
		}
    }
			
	if(found==false)//�S���P�� 
	{
		count++;
		
		b[j][sum[j]]=a[i][0];//�N��Ʀs�J�s���@�Z 
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
