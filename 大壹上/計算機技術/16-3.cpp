#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<math.h> 

char input[42];
int  len,number[2][40]={0},point,sum[40],i,j,c=0,begin=-1,end=-1,num[2][40],sign[2]={1,1};

int main()
{
	for(i=0;i<=1;i++)
	{
		printf("please input number#%d:",i+1);
	    scanf("%s%*c",input);
	    len=strlen(input);
	    point=-1;
	    
	    for(j=0;j<len;j++)
	    {
			if(input[j]=='.') 
	    	  point=j;
	    	  
	        if(input[j]=='-')
	        {
	        	sign[i]=0;
	            input[j]='0';
			}  
	    	 
	    }	   	  
	    	  
	    if(point==-1)	   
	        for(j=len-1;j>=0;j--) 
		      number[i][20-len+j]=(int)input[j]-48;
	      
	    else
		{
			for(j=point-1;j>=0;j--)
			   number[i][20-point+j]=(int)input[j]-48;
			for(j=point+1;j<=len-1;j++)
			   number[i][19-point+j]=(int)input[j]-48;
			
		}  
	}
 

if(sign[0]==0 && sign[1]==0)
{
	for(i=39;i>=0;i--)
	{
		sum[i]=number[0][i]+number[1][i]+c;
		
		if(sum[i]>9)
		{
			sum[i]=sum[i]-10;
			c=1;
		}
		
		else c=0;
	}
	
	for(i=0;i<=19;i++)
	   if(sum[i]!=0) {begin=i; break;}
	   
	for(i=39;i>=20;i--)
	   if(sum[i]!=0) {end=i; break;}   
	   
	printf("the sum is ");
	if(c==1) printf("-1");
	
	if(begin==-1) printf("0");
	
	else 
	{
		printf("-");
		for(i=begin;i<=19;i++)
	      printf("%d",sum[i]);
	}
	   
	
	if(end!=-1)
	{
		printf(".");
		for(i=20;i<=end;i++)
		   printf("%d",sum[i]);
		
    }      
}

else
{
	  for(i=0;i<40;i++)
	  {
	  	num[0][i]=number[0][i];
	  	num[1][i]=number[1][i];
	  }
	
	  
	  
	for(i=39;i>=0;i--)
	{
		sum[i]=num[0][i]-num[1][i]+c;
		
		if(sum[i]<0)
		{
			sum[i]=sum[i]+10;
			c=-1;
		}
		
		else c=0;
	}
	  
	  
	for(i=0;i<=19;i++)
	   if(sum[i]!=0) {begin=i; break;}
	   
	for(i=39;i>=20;i--)
	   if(sum[i]!=0) {end=i; break;}   
	   
	printf("the sum is ");
	
	if(sign[0]==0) 
	   printf("-");
	   
	
	if(begin==-1) printf("0");
	
	else 
		for(i=begin;i<=19;i++)
	      printf("%d",sum[i]);
	
	if(end!=-1)
	{
		printf(".");
		for(i=20;i<=end;i++)
		   printf("%d",sum[i]);
		
    }        
	  
	    
}

}
