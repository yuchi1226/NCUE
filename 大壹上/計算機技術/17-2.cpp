#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<math.h> 

int main()
{
	char letter[15];
	int len,B;
	
	while(1)
	{
		int i=0,v=0,x=0,l=0,c=0,d=0,m=0,sum=0,count=0,count_t=0,A,a=0;
	    char con='a';
	    
	printf("請輸入介於1~3999之間的羅馬數字:");
	scanf("%s",letter);
	
	len=strlen(letter);
	for(A=0;A<len;A++)
	{
		
		if(letter[A]=='I')
		  sum++;
		else if(letter[A]=='V')
		  sum=sum+5;
		else if(letter[A]=='X')
		  sum=sum+10;
		else if(letter[A]=='L')
		  sum=sum+50;
		else if(letter[A]=='C')
		  sum=sum+100;
		else if(letter[A]=='D')
		  sum=sum+500;
		else if(letter[A]=='M')
		  sum=sum+100;
		else if(letter[A]=='I'&&letter[A+1]=='V')
		  sum=sum-2;
		else if(letter[A]=='I'&&letter[A+1]=='X')
		  sum=sum-2;
		else if(letter[A]=='X'&&letter[A+1]=='L')
		  sum=sum-20;
		else if(letter[A]=='X'&&letter[A+1]=='C')
		  sum=sum-20;
		else if(letter[A]=='C'&&letter[A+1]=='D')
		  sum=sum-200;
		else if(letter[A]=='C'&&letter[A+1]=='M')
		  sum=sum-200;  
		  
		  
		else if(letter[A]=='K')
		  break;
		else if(con=='X' && letter[A]=='D') 
		  break;
		else if(sum==254 || sum==1605 || sum==2515 || sum==119 )   
		  break;
		
		if(letter[A]==con)
		{
			if(letter[A]=='V' ||letter[A]=='L' ||letter[A]=='D' )
			  count_t++;
			else
			  count++;
		}  
		else
		{
		  con=letter[A];
		  
		  if(letter[A]=='V' ||letter[A]=='L' ||letter[A]=='D' )
			  count_t=1;
			else
			  count=1;
		}  
		 
		if(count==4 ||count_t==2)
		  break;
	}
	
	if(i<len)
	    printf("羅馬數字輸入錯誤!!\n");
	    
	else
		printf("轉成阿拉伯數字為%d\n",sum);
	
	}  
}
