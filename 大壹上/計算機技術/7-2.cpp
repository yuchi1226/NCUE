#include<stdio.h> 
#include<stdlib.h> 

int main()
{
	int a,b,i=0,m[1000],r,j;
	
	
	printf("please input a decimal number:");
	scanf("%d",&a);

	do{               
         r = a%2;     
		
         a = a/2;
         i++;
         m[i] = r; 
        
     }while(a != 0);
	

	
	for(j = i; j > 0; j--)      
        printf("%d",m[j]);


    printf("\n");

	
	long long int c,n=1,dec=0;
	
	printf("please input a binary number:");
	scanf("%lld",&c);
	
	while(c!=0)
	{
		dec=dec+n*(c%10);
		n=n*2;
		c=c/10;
	}
	
		printf("%lld",dec);
	

	
	
	
}
