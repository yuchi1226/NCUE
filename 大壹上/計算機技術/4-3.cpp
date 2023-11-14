#include <stdio.h> 
#include <stdlib.h> 

int main()
{
	int a,b,p1,p2,mul;
	
	printf("please input two integers: ");
	scanf("%d %d",&a,&b);
	
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
	
	printf("%d",p2);
}
