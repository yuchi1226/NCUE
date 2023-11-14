#include <stdlib.h>
#include <stdio.h>
int count=0;
void towers(int n,char from,char aux,char to)
{
	
	if(n>=1)
	{
		towers(n-1,from,aux,to);
		printf("ring %d:%c=>%c\n",n,from,to);
		towers(n-1,aux,from,to);
		count++;
	}
} 

int main()
{
	int n;
	char a,b,c;
	
	printf("請輸入A柱中的環個數:");
	scanf("%d",&n);
	towers(n,'A','B','C');
	printf("共需%d個步驟",count);
	
}


