#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<math.h> 

int main()
{
	int y,m,d,y0,m0,d0,i;
	int count=0;
	
	printf("�п�J�褸�}�l���:");
	scanf("%d/%d/%d",&y,&m,&d);
	printf("�п�J�褸�������:");
	scanf("%d/%d/%d",&y0,&m0,&d0);
	
	for(i=y;i<=y0;i++)
	{
		if(i%400==0) count++;
		
		else if(i%4==0 && i%100!=0) count++;
		
		else if(i%4!=0) continue;
		
		else if(i%100==0 && i%400!=0) continue;
		
	}
	
	
	
	printf("��������2��29��@��%d��",count);
}
