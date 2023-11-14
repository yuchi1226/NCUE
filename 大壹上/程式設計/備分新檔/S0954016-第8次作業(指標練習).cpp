#include<stdio.h> 
#include<stdlib.h> 

int main()
{
	char a,b,c,s,m,l;
	
	printf("½Ð¿é¤J3¦r¤¸:");
	scanf("%1c%1c%1c",&a,&b,&c);
	
	if(a>=97 && a<=122)
	   a=a-32;
	
	if(b>=97 && b<=122)
	   b=b-32;
	   
	if(c>=97 && c<=122)
	   c=c-32;     
	
	do
	{
		if(a>b && a>c)
		{
			l=a;
			
			if(b>c)
			{
				m=b;
				s=c;
			}
			else
			{
				m=c;
				s=b;
			}
		}
		
		if(b>a && b>c)
		{
			l=b;
			
			if(a>c)
			{
				m=a;
				s=c;
			}
			else
			{
				m=c;
				s=a;
			}
		}
		
		if(c>b && c>a)
		{
			l=c;
			
			if(b>a)
			{
				m=b;
				s=a;
			}
			else
			{
				m=a;
				s=b;
			}
		}
		
		
		
	}while(s>m || s>l || m>l);
	
	printf("%1c%1c%1c\n",s,m,l);
	
	system("pause");  
}
