#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

Integers(int a, int b)
{
    int x,y;
	 
	if(a<b)
	{
		x=a;y=b;//�p����bx �j����by 
	}
	else
	{
		y=a;x=b;
	}
	
	cout<<x<<" "<<y<<endl;
}
Floating(float a, float b)
{
	float x,y;
	 
	if(a<b)
	{
		x=a;y=b;//�p����bx �j����by 
	}
	else
	{
		y=a;x=b;
	}
	
	cout<<x<<" "<<y<<endl;
}


int main()
{
	char type[11],in[2]="i",flo[2]="f";
	int i=0;

while(cout<<"Integers or Floating?")
{

	cin>>type;
	
	if((type[0]-in[0])==0 )
	{
		int a,b;
		
		cout<<"�п�J����:";
		scanf("%d %d",&a,&b);
		
		Integers(a, b);
	} 
	else if((type[0]-flo[0])==0 )
	{
		float a,b;
		
		cout<<"�п�J��B�I��:";
		scanf("%f %f",&a,&b);
		
		Floating(a, b);
	} 
	else
	    cout<<"wrong! please intput Integers or Floating"<<endl;
	
}
	return 0;
} 
