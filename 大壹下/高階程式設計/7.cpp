#include<iostream>
#include<stdio.h>
#include <math.h>
using namespace std;

int main()
{
	double a,b;
	double i,j,point;
	double x,result;

while(cin>>a>>b)	
{	
	for(i=a;i<=b;i++)
	{
		if(b<i*pow(2,0.5)) 
            break;
	
		for(j=i;j<=b;j++)
		{   				
			x=(i*i)+(j*j);
			result=(int)sqrt(x);
							    			       
			if(x==result*result && a<=result && result<=b)
			    point++;
		}		 
	}		   
    cout<<point<<endl;
    point=0;
		    
}//whileµ²§ô 
	
}
