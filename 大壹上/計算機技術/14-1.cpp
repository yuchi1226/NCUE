#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
#include<math.h> 

int main()
{
	int a=0,b=0,c,i,j,k,h,num,len;
	int c10[2000],count=0;
	char input[20],t10[2000][20],t11[2000][20];
	
	
	FILE *Data1;
	FILE *Data2;	
	Data1=fopen("t10.txt","r");
	Data2=fopen("t11.txt","r");
	
	for(c=0;c<2000;c++)
	   c10[c]=1;
	
if(Data1!=NULL && Data2!=NULL)
{
	while(fscanf(Data1,"%s",input)==1)
	{
		len=strlen(input);
		
		if(input[len-1]==',' || input[len-1]=='.')
			   input[len-1]='\0';
			   
		if(65<=(int)input[0] && (int)input[0]<=90)
			input[0]=input[0]+32;
			 
		strcpy(t10[a],input);
		a++;
	}
	while(fscanf(Data2,"%s",input)==1)
	{
		len=strlen(input);
		
		if(input[len-1]==',' || input[len-1]=='.')
			   input[len-1]='\0';
			   
		if(65<=(int)input[0] && (int)input[0]<=90)
			input[0]=input[0]+32;
			
		strcpy(t11[b],input);
		b++;
	}
	
	for(i=0;i<a;i++)
	    for(j=0;j<b;j++)
	    {
	    	count=0;
	    	
	    	if(strcmp(t10[i],t11[j])==0)
			{
				count++;
				
				while(strcmp(t10[i+count],t11[j+count])==0)
					count++;
			
				
				if(count>=7)
				{
					for(k=0;k<count;k++)
					   c10[i+k]=0;
				}   
				
			}  
		}
		
    for(h=0;h<a;h++)
	{
		if(c10[h]==0)
		  num++;
		
	}		
	
	printf("%d/%d=%.2f%%",num,a,100*(float)num/a);
	
}	
fclose(Data1);
fclose(Data2);
}
