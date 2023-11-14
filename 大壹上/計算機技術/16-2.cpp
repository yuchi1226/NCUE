#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<time.h> 

int n,remainder,choose,i,sum=0;

int main()
{
	srand(unsigned( time(NULL) ));
    n = rand()%31+10;
    printf("N=%d\n",n);
    while(1)
    {
    	remainder=(n-sum)%4;
    	if(remainder==0) choose=3;
    	else if(remainder==3) choose=2;
    	else choose=1;
    	
    	printf("sum=%d,computer add %d \n",sum,choose);
    	sum=sum+choose;
    	
    	if(sum==n)
    	{
    		printf("sum=%d,ypu win!!!",sum);
    		break;
		}
		
		do{
			
			printf("sum=%d you add",sum);
			scanf("%d",&i);
			
			if(i>3 || i<1) printf("please input 1 2 or 3\n");
			if(i>n-sum) printf("overflow\n");
			 
		}while(i>3 || i<1 || i>n-sum);
		
		sum=sum+i;
		
		if(sum==n)
		{
			printf("sum=%d,ypu lost!!!",sum);
    		break;
		}
	}
    
       
	
}
