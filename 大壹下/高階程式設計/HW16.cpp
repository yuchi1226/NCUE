#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include<stdio.h>
#include <string.h>
using namespace std;

int main()
{
	int num,i,j,k;
	
while(cin>>num)
{	
	getchar();
	
	for(i=0;i<num;i++)
	{
		int n=0,max=0,first=0;
		long long int row[100000]={0};
		long long int much[100000]={0};//�s���X�ӼƦr��Y�ӤϨ��
		char c;
		
		
		
		while((c=getchar())!='\n')
    	{
	        if(c!=' ')
	        {
	            ungetc(c,stdin);
	            cin>>row[n++];//�@��Jn�ӼƦr 
	        }
    	}
						           
		
		for(j=0;j<n;j++)
		{
			int count=0;
			
			for(k=0;k<j;k++)
				if(row[k]>row[j])
					count++;
					
			for(k=j+1;k<n;k++)
				if(row[k]<row[j])
					count++;	//��X�ثe��j�Ӫ��Ϩ�� 
					
			if(count>=max)
			{
				max=count;
				much[j]=max;
			} 	
					
		}
		
		 for(j=0;j<n;j++)
		 {
		 	if(much[j]==max)
			{
				if(first==0)
				{
					cout<<row[j];
					first++;
				}
				else
					cout<<", "<<row[j];
			}
		 }
		
		cout<<" "<<max<<endl;
	}
	
}//while end	
	
} 
