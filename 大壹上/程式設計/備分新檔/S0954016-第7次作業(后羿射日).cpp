#include <iostream>
#include<stdio.h> 
#include<stdlib.h> 


int main()
{
	int x0,y0,l0,r,n,x1,y1,l1,s,a,i;
	
	printf("�п�Jx�y�ЭȻPy�y�ЭȡB���Ťήg�{�d��R�C");
	scanf("%d %d %d %d",&x0,&y0,&l0,&r);	
	if(x0<-1000 || x0>1000 || y0<-1000 || y0>1000 || l0<1 || l0>5 || r<0 || r>3000)
	  printf("��J���ƭȤӤj�ΤӤp�C");
	
	printf("���X���Ӷ�?");
	scanf("%d",&n);
	
	printf("�п�J�Ӷ���x�y�ЭȻP y�y�ЭȤε���\n");
	for(s=1,i=0;s<=n;s++)	
	{
		scanf("%d %d %d",&x1,&y1,&l1);
		
		if(x1<-1000 || x1>1000 || y1<-1000 || y1>1000 || l1<1 || l1>5 )
	       printf("��J���ƭȤӤj�ΤӤp�C");
	       
	    
		if((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1)<=r*r && l0>=l1)
		    i++;	      
	}
	
	printf("�g�U%d�ӤӶ�",i);
}



