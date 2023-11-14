#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include<stdio.h>
#include <string.h>
using namespace std;

int main()
{
	int s,p;//學生和老師的人數
	int i,j,k,m,n;
		
while(cin>>s>>p)
{
	int sperfer[s][p],pperfer[p][s];
	int list[s],found[s],num=0;
	
	for(i=0;i<s;i++)
		for(j=0;j<p;j++)
			cin>>sperfer[i][j];
			
	for(i=0;i<p;i++)
		for(j=0;j<s;j++)
			cin>>pperfer[i][j];
			
	for(i=0;i<s;i++)
	{
		list[i]=-1;	
		found[i]=-1;
	}	
			
	for(i=0;i<p && num!=s ;i++)//學生的喜愛度遞減 
	{
		int clas[p][s],sum[s];
				
		for(j=0;j<p;j++)
		{
			sum[j]=0;
			 
			for(k=0;k<s;k++)
				clas[j][k]=-1;
		}		
		
		for(j=0;j<s;j++)//學生編號EX:Sj 
		{	
			for(n=0;n<s;n++)
				if(j==found[n])
					break;
						
				if(n>=s)
				{
					clas[sperfer[j][i]][sum[sperfer[j][i]]]=j;//EX:把喜歡P0教授的學生關到clas0 
					sum[sperfer[j][i]]++;
				}
		}
		
		for(m=0;m<p;m++)//Pi 
			for(j=0;j<s;j++)//Pi的喜好排序 
				for(k=0;k<s;k++)
				{				
					if(clas[m][k]==-1)
						break;
					
					if(pperfer[m][j]==clas[m][k])
					{
						for(n=0;n<s;n++)
							if(m==list[n])
								break;
						
						if(n>=s)
						{
							list[pperfer[m][j]]=m;
							found[num]=pperfer[m][j];
							num++;
							break;
						}
					} 
				}
					
			
			
	}	
	
	for(i=0;i<s;i++)
		cout<<list[i]<<" ";		
		
	cout<<endl;	 
	
}		
	
} 
