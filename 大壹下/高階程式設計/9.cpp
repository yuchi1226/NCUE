#include<iostream>
#include<stdio.h>
#include <math.h>
using namespace std;

int main()
{
	int r,c,i,j;
	int sum=0,point=0;
	int arr[100][20]={0};
	
	while(cin>>r>>c)
	{
		for(i=1;i<=r;i++)
			for(j=1;j<=c;j++)
			{
				cin>>arr[i][j];
				
				if(arr[i][j]==1)
				   sum++;
			}	
				
		for(i=1;i<=r;i++)
			for(j=1;j<=c;j++)
			{	
				if(arr[i][j]==5)
				{
					if(arr[i-1][j-1]==5 || arr[i-1][j]==5 || arr[i-1][j+1]==5 || arr[i][j-1]==5 || arr[i][j+1]==5 || arr[i+1][j-1]==5 || arr[i+1][j]==5 || arr[i+1][j+1]==5 )
					  continue;
					
					if(arr[i-1][j-1]==1)//11
					{
					point++;  
					arr[i-1][j-1]=0;
				    }
					if(arr[i-1][j]==1)//12
					{
					point++;  
					arr[i-1][j]=0;
				    }  
					
					if(arr[i-1][j+1]==1)//13
					{
					point++;  
					arr[i-1][j+1]=0;
				    }  
					
					if(arr[i][j-1]==1)//21
					{
					point++;  
					arr[i][j-1]=0;
				    } 
					
					if(arr[i][j+1]==1)//23
					{
					point++;  
					arr[i][j+1]=0;
				    }  
					
					if(arr[i+1][j-1]==1)//31
					{
					point++;  
					arr[i+1][j-1]=0;
				    }
					
					if(arr[i+1][j]==1)//32
				    {
					point++;  
					arr[i+1][j]=0;
				    }
					
					if(arr[i+1][j+1]==1)//33
					{
					point++;  
					arr[i+1][j+1]=0;
				    }  
					   
				}
			}
			
		printf("%d %d",point,sum-point);			
				
	}
} 
