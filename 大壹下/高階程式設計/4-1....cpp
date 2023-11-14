#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{

    int a,i,j;
    int number[10000][2],temp;
    int left,right,index,sum=0;
    
	for(i=0;i<10000;i++)
	    for(j=0;j<2;j++) 
	        number[i][j]=0;
	   
	cin>>a;
	
	for(i=0;i<a;i++)
	   cin>>number[i][0]>>number[i][1];
	   
	for(i=0;i<a;i++)//®ğªw±Æ§Ç 
        for(j=0;j<i;j++) 
		{
            if (number[j][0]>number[i][0]) 
			{
                temp=number[j][0];
                number[j][0]=number[i][0];
                number[i][0]=temp;
                
                temp=number[j][1];
                number[j][1]=number[i][1];
                number[i][1]=temp;
            }
        }
       
    
    for(i=0;i<a;i++)
    {
        left=number[i][0];
    	right=number[i][1];
    	
    	if(index>left)
    	{
    		sum=sum+right-index; 
    		continue;
		}
            
        else    
            sum=sum+right-left; 
		   
		index=right;
    	
	} 
    
	cout<<sum<<endl;

  
}
