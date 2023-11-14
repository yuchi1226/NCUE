#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int a,b;
	int i,j,x,temp; 
	int length,width,long1,long2,area1,area2;
	int arr[100][3]={0};//邊、長、面積資料
	
while(cin>>a)//幾組測資
{
	
	for(i=0;i<a;i++)
	{
		cin>>b;//幾筆邊長
		int point=0; 		
		for(j=0;j<b;j++)
		{
			cin>>length>>width;
			
			if(length>width)
			{
				arr[j][0]=width;
				arr[j][1]=length;
			}
			else
			{
				arr[j][0]=length;
				arr[j][1]=width;
			}
			arr[j][2]= width*length;
		}    
			
		for(x=0;x<b;x++)//氣泡排序 
            for(j=0;j<x;j++) 
		    {
                if (arr[j][0]<arr[x][0]) 
			    {
                    temp=arr[j][0];
                    arr[j][0]=arr[x][0];
                    arr[x][0]=temp;
                
                    temp=arr[j][1];
                    arr[j][1]=arr[x][1];
                    arr[x][1]=temp;
                    
                    temp=arr[j][2];
                    arr[j][2]=arr[x][2];
                    arr[x][2]=temp;
                }
            }
			
		
		long1=arr[0][1];
		area1=arr[0][2];
		
		for(j=1;j<b;j++)
		{
		    long2=arr[j][1];
			area2=arr[j][2];
			   
			if(long1>=long2 && area1>=area2)
			{
			    long1=arr[j][1];
			    area1=arr[j][2];
				point++;
			}
			    
		}
			
		cout<<point+1<<endl;
			 
	}
	
	
	    
	    
}//while結束 

}
