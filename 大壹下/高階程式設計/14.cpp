#include <iostream>
#include <iomanip>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
	char a[101],b[101];
	int i=0,j=0,k,star,la,lb,max,temp;
	
while(cin>>a)
{
	cin>>b;
	cin>>star;
	
	la=strlen(a);
	lb=strlen(b);
	
	int arr[la+1][lb+1];
	int brr[la+1][lb+1];
	
	for(i=0;i<=la;i++)
		for(j=0;j<=lb && j<=i;j++)
		{
			if(i<=j || i-j>=la-lb)//�b����-->��l�Ʋ{�b���p�� 
		    {
		    	arr[i][j]=0;
		    	brr[i][j]=1;
			}
		    
			if(i==j)//�@�ӹ�@�� 
			{
				arr[i][j]=0;
				brr[i][j]=1;//���θ�star//�N�@�ؤ覡�|�̤j 
				
				if(i==0)
					arr[i][j]=0;
			
				for(k=1;k<=i;k++)
					arr[i][j]+=abs((a[k-1]-'A'+1)-(b[k-1]-'A'+1));
			}
			else//i!=j 
			{
				if(j==0)//arr[i-1][j]+(a[i-1]-"*")
				{
					arr[i][j]=arr[i-1][j]+abs((a[i-1]-'A'+1)-star);
					max=arr[i][j];
					brr[i][j]=1;//j<=i -->�֪�j����* -->�u���@�ض�ɤ覡 
				}
				if(j!=0)//�����ا�̤j 
				{
					max=arr[i-1][j]+abs((a[i-1]-'A'+1)-star);
					temp=arr[i-1][j-1]+abs((a[i-1]-'A'+1)-(b[j-1]-'A'+1));
					
					if(max>temp)
						brr[i][j]=brr[i-1][j];//��ɤ覡��max�� 
					else if(max<temp)
					{
						max=temp;
						brr[i][j]=brr[i-1][j-1];
					}	
					else
						brr[i][j]=brr[i-1][j]+brr[i-1][j-1];
					
					arr[i][j]=max;		
				}
			}	
	    }
	
	printf("%d %d\n",arr[la][lb],brr[la][lb]);  
	
	
}//while end
	
}
