#include<stdio.h> 
#include<stdlib.h> 

int main()
{
	int a,b,i,c,i1,j;
	int count[10]={0,0,0,0,0,0,0,0,0,0};
	
	printf("�п�JA:B....");
	scanf("%d %d",&a,&b);
	
	for(i=a;i<=b;i++)
	{
		i1=i;
		
		for(;i1>0;)
		{
			c=i1%10;
			count[c]++;
			i1=i1/10;
			
		}
		
	} 
	
	
	printf("0~9�X�{�����Ƭ�....");
	
	for(j=0;j<=9;j++)
	   printf("%d,",count[j]);
}
