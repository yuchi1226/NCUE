#include <stdio.h> 
#include <stdlib.h> 

int main()
{
	int n,y,count=0,i,m[12],week;
	
	printf("please input the century:");
	scanf("%d",&n);
	
	for(y=n*100-99;y<=100*n;y++)
	{
		week=(y+(y-1)/4-(y-1)/100+(y-1)/400)%7;
		if(week==0)
		   count++;
		
		if(y%4==0 && y%100!=0)
		{
			m[2]=week+31;
			m[3]=m[2]+29;
			m[4]=m[3]+31;
			m[5]=m[4]+30;
			m[6]=m[5]+31;
			m[7]=m[6]+30;
			m[8]=m[7]+31;
			m[9]=m[8]+31;
			m[10]=m[9]+30;
			m[11]=m[10]+31;
			m[12]=m[11]+30;
			
			for(i=2;i<=12;i++)
			{
				if(m[i]%7==0)
				   count++;
			}
			
		}
		else if(y%400==0)
		{
			m[2]=week+31;
			m[3]=m[2]+29;
			m[4]=m[3]+31;
			m[5]=m[4]+30;
			m[6]=m[5]+31;
			m[7]=m[6]+30;
			m[8]=m[7]+31;
			m[9]=m[8]+31;
			m[10]=m[9]+30;
			m[11]=m[10]+31;
			m[12]=m[11]+30;
			
			for(i=2;i<=12;i++)
			{
				if(m[i]%7==0)
				   count++;
			}
		}
		else
		{
			m[2]=week+31;
			m[3]=m[2]+28;
			m[4]=m[3]+31;
			m[5]=m[4]+30;
			m[6]=m[5]+31;
			m[7]=m[6]+30;
			m[8]=m[7]+31;
			m[9]=m[8]+31;
			m[10]=m[9]+30;
			m[11]=m[10]+31;
			m[12]=m[11]+30;
			
			for(i=2;i<=12;i++)
			{
				if(m[i]%7==0)
				   count++;
			}
		}		
		
	}
	
	printf("%d times!!",count);
}
