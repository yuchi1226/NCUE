#include <iostream>
#include<stdio.h> 
#include<stdlib.h> 


int main()
{
	int x0,y0,l0,r,n,x1,y1,l1,s,a,i;
	
	printf("請輸入x座標值與y座標值、等級及射程範圍R。");
	scanf("%d %d %d %d",&x0,&y0,&l0,&r);	
	if(x0<-1000 || x0>1000 || y0<-1000 || y0>1000 || l0<1 || l0>5 || r<0 || r>3000)
	  printf("輸入的數值太大或太小。");
	
	printf("有幾顆太陽?");
	scanf("%d",&n);
	
	printf("請輸入太陽的x座標值與 y座標值及等級\n");
	for(s=1,i=0;s<=n;s++)	
	{
		scanf("%d %d %d",&x1,&y1,&l1);
		
		if(x1<-1000 || x1>1000 || y1<-1000 || y1>1000 || l1<1 || l1>5 )
	       printf("輸入的數值太大或太小。");
	       
	    
		if((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1)<=r*r && l0>=l1)
		    i++;	      
	}
	
	printf("射下%d個太陽",i);
}



