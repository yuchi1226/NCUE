#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a,b,p1,p2,mul,c;
	
	printf("�п�J����Ϊ���...");
	scanf("%d",&a);
	
	printf("�п�J����Ϊ��e...");
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
	
	printf("�ֻ̤ݭn%d�ӬۦP������ΡA�Ʀ������%d�������",(a/c)*(b/c),(a*b)/c);
}
