#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<math.h> 

int main()
{
	int y,m,d,y0,m0,d0;
	int a,b,c,sum,count;
	
	printf("請輸入西元開始日期:");
	scanf("%d/%d/%d",&y,&m,&d);
	printf("請輸入西元結束日期:");
	scanf("%d/%d/%d",&y0,&m0,&d0);
	
	sum=y0-y+1;
	
	a=sum/4;
	b=sum/100;
	c=sum/400;
	
	count=a-b+c;
	
	if(((y%4==0 && y%100!=0) || y%400==0) && m>=3 ) count--;
	
	if(((y0%4==0 && y0%100!=0) || y0%400==0) && m0<=2 && d0<29 ) count--;
	
	if(((y%4==0 && y%100!=0) || y%400==0) && ((y0%4==0 && y0%100!=0) || y0%400==0)) count++;
	
	printf("此期間的2月29日共有%d次",count);
	
	
	
	
	
	
}
