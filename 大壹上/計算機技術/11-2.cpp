#include <stdio.h> 
#include <stdlib.h> 

int sort(int n)
{
	int number,money,a,b,c,d,min,m;
	int car1,car2,car3,car4;
	
	m=n/16;
	if(n%16!=0)
	  m++;
	  
	min=7500*m;
	car4=m;  
	
	for(d=0;d<m;d++)
	{
		for(c=0;c<=(n-d*16)/13+1;c++)
		{
			for(b=0;b<=(n-d*16-c*13)/7+1;b++)
		    {
		    	if(d*16+c*13+b*7>=n)
		    	  a=0;
		    	else
				{
					a=(n-d*16-c*13-b*7)/4;
					if((n-d*16-c*13-b*7)%4!=0)
					   a++;  
		    		
				}  
				
				if(2500*a+3800*b+6400*c+7500*d<min)
				{
					min=2500*a+3800*b+6400*c+7500*d;
					car1=a;
		            car2=b;
		            car3=c;
		            car4=d;
				}
			
		    }
		}
		
	}
	
	printf("�ֻ̤ݭn %d��\n",min);
    printf("�|���Ш� %d\n",car1);
    printf("�Ӱȥ�Ȩ� %d\n",car2);
	printf("�p���ڤh %d\n",car3);			
	printf("�����ڤh %d\n",car4);	
	
}

int main()
{
	int n;
	
	printf("�п�J�����`�H��:");
	scanf("%d",&n);
	
	sort(n);
}
