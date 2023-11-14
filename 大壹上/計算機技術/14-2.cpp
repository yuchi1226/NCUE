#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<math.h> 

int main()
{
	int i,j,k;
	int len,max=0,count;
	char input[101];
	
	FILE *Data1;	
	FILE *Data2;
	Data1=fopen("t7.txt","r");
	Data2=fopen("t8.txt","w");
	
if(Data1!=NULL && Data2!=NULL)
{
	while(fscanf(Data1,"%s",input)==1)
	{
		max=0;
	    len=strlen(input);
	    
	    for(i=0;i<=len-1;i++)
	    { 
	        for(j=len-1;j>=i;j--)
	        {
	        	if(input[j]==input[i])
	        	{
	        		for(k=0;k<=(j-i)/2;k++)
						if(input[i+k]!=input[j-k])
						    break;
					
					if(k>(j-i)/2)
					{
					    if(j-i+1>max)
					    {
					    	max=j-i+1;
					    	count=1;
						}
						
						else if(j-i+1==max)
						    count++;
						    
						break;    
				    }   
							 
				}
					
			} 
					   
		}
			
		fprintf(Data2,"%d,%d\n",max,count);  	
	}
		
		
}
	
	fclose(Data1);
    fclose(Data2);
    
}
