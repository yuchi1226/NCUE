#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;

long long int gcd(long long int b2, long long int c2) //程そ计 
{
    while(c2!= 0) 
	{ 
        int r = b2%c2; 
        b2=c2; 
        c2=r; 
    } 
    return b2;
}

long long int lcm(long long int b2, long long int c2) //程そ计 
{
    return b2*c2 / gcd(b2,c2);
}

int main()
{
	long long int a,b,c,x,y,z;
	char sign[2];
	long long int b1,c1,y1,z1;
	long long int a2,b2,c2;
	int i;
	
	while(scanf("%lld %lld %lld %s %lld %lld %lld",&a,&b,&c,sign,&x,&y,&z)!=EOF)
	{
		b1=a*c+b;
		c1=c;
		
		y1=x*z+y;
		z1=z;//盢盿だ计传Θ安だ计 
		
		if(strcmp(sign,"*")==0 || strcmp(sign,"/")==0) //埃 
		{
			
			if(strcmp(sign,"*")==0)
			{
				b2=b1*y1;
				c2=c1*z1;
					
			}
			
			if(strcmp(sign,"/")==0)
			{
				b2=b1*z1;
				c2=c1*y1;
					
			}
			
			a2=b2/c2;
			b2=b2-a2*c2;
			
			if(b2==0)
			{
				printf("%lld\n",a2);
			}
			else
			    printf("%lld %lld %lld\n",a2,b2/gcd(b2,c2),c2/gcd(b2,c2));			
			
		}
		
		if(strcmp(sign,"+")==0 || strcmp(sign,"-")==0) //搭
		{
			i=lcm(c1, z1);
			b1=b1*(i/c1);
			c1=i;
			
			i=lcm(c1, z1);
			y1=y1*(i/z1);
			z1=i;
			//传Θだダ 
			
			if(strcmp(sign,"+")==0)
			{
				b2=b1+y1;
                c2=i;
			} 
			
			if(strcmp(sign,"-")==0)
			{
				b2=b1-y1;
                c2=i;
			} 
			
			a2=b2/c2;
			b2=b2-a2*c2;
			
			if(b2==0)
			{
				printf("%lld\n",a2);
			}
			else
			    printf("%lld %lld %lld\n",a2,b2/gcd(b2,c2),c2/gcd(b2,c2));
		} 
		
	}
	
} 
