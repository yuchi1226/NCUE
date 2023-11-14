#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a,b,p1,p2,mul,c;
	
	printf("請輸入長方形的長...");
	scanf("%d",&a);
	
	printf("請輸入長方形的寬...");
	scanf("%d",&b);
	
	if(a<b)
	  {
	  	p2=b;
	    p1=a;
	  }
	  
	else if(a>b)
	  {
	    p2=a;
	    p1=b;
	  }
	  
	do{
		mul=p2%p1;
		
		p2=p1;
		p1=mul;
		
	  }while(mul!=0);
	
	c=p2;
	
	printf("最少需要%d個相同的長方形，排成邊長為%d的正方形",(a/c)*(b/c),(a*b)/c);
}
