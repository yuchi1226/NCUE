#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<math.h> 

int main()
{
	int i,j,k,len,a,b,c=0,max=0,count=0;
	int list[100][2];
	char input[20];
	
	printf("please input char:");
	scanf("%s",input);
	
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
					    count=0;
					    list[count][0]=i;
					    list[count][1]=j;
					}
						
					else if(j-i+1==max)
					{
						count++;
						list[count][0]=i;
					    list[count][1]=j;
					}	
						    
					break;    
				}   
							 
			}
					
		} 
					   
	}
	
	printf("最常迴文為:");
	for(a=0;a<=count-1;a++)
	{
		for(b=list[c][0];b<=list[c][1];b++)
		{
			printf("%c",input[b]);
		}
		
		printf(",");
		c++;
	}
	
	for(b=list[c][0];b<=list[c][1];b++)
		printf("%c",input[b]);

}
