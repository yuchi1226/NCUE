#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a,b;
	char choice,y,Y;
		
	do{
	    printf("�п�Jn1:");
	    scanf("%d",&a);

        printf("�п�Jn2:");
	    scanf("%d",&b);
	    
		if(a>b)
	       {
		   printf("Error!!Number1>Number2\n");
           continue;
		   }

	   	else
		   {
		   printf("Sum=%d\n",(a+b)*(b-a+1)/2);
	   	
		   printf("Again(Y/N)");
	   	   scanf("%*c%c",&choice);

	       }
	   }while(choice!='n'&& choice!='N');
	
	      
}

