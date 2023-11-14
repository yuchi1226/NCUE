#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

int main()
{
	int a,str[50],i,j,k,temp,temp2,count=0;
	char ch;
	
	FILE *Data1;	
	FILE *Data2;
	FILE *Data3;
	Data1=fopen("Hello.txt","r");
	Data2=fopen("11-2.txt","w+");
	Data3=fopen("11-2-2.txt","w");	
	
	if(Data1!=NULL && Data2!=NULL)
	{
		while((ch=fgetc(Data1))!=EOF)
		{
			str[a]=ch;
			a++;
		}
			   
		for(i=0;i<2*a;i++)
		{
			if(i%8==0)
			{
				temp=str[i+1];
				str[i+1]='M';
				
				for(j=a+i-1;j>i+1;j--)
					str[j+1]=str[j];
				
				str[i+2]=temp;
				
				count++;	
			}
			
			if(i%8==2)
			{
				temp=str[i+1];
				str[i+1]='a';
				
				for(j=a+i-1;j>i+1;j--)
					str[j+1]=str[j];
				
				str[i+2]=temp;
				
				count++;	
			}
			
			if(i%8==4)
			{
				temp=str[i+1];
				str[i+1]='r';
				
				for(j=a+i-1;j>i+1;j--)
					str[j+1]=str[j];
				
				str[i+2]=temp;	
				
				count++;
			}
			
			if(i%8==6)
			{
				temp=str[i+1];
				str[i+1]='y';
				
				for(j=a+i-1;j>i+1;j--)
					str[j+1]=str[j];
				
				str[i+2]=temp;	
				
				count++;
			}
			
		}	   
		
			  
		for(k=0;k<a+count;k++)
		    fprintf(Data2,"%c",str[k]);
		
		
		for(i=1;i<50;i++)
		{
			if(i%4==1)				
				for(j=i;j<50-i;j++)
					str[j]=str[j+1];	
			
			if(i%4==2)
			    for(j=i;j<50-i;j++)
					str[j]=str[j+1];
			
			if(i%4==3)
			    for(j=i;j<50-i;j++)
					str[j]=str[j+1];
			
			if(i%4==0)
			    for(j=i;j<50-i;j++)
					str[j]=str[j+1];
			
		}	   
		
			  
		for(k=0;k<a;k++)
		    fprintf(Data3,"%c",str[k]);
		
		
		
		
		
	}
	
	fclose(Data1);
	fclose(Data2);
	fclose(Data3);
	
} 
