#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;

int main()
{
	char a[100000];
	int len,i,j,k;
	
	while(scanf("%s",a)!=EOF)
	{
		int total=0,max=0,sum=0;
		char a1[1000][1000]={0};
		int b1[1000],b2[1000],num[1000]={0};
	
		len=strlen(a);
		
		for(i=0;i<len-1;i++)//從頭開始 
		    for(j=len-1;j>i&&j-i+1>=max;j--)//從尾找回一樣的字元 //終止條件:i,j之間長度小於max 
		    {
			    
		    	if(a[i]!=a[j])
		    	   continue;
		    	else //如果找到 
				{
					for(k=1;k<=(i+j)/2-i;k++)//對比到中間看是否一樣 
				   	    if(a[i+k]-a[j-k]!=0)
				   	        break;
				   
				   if(k>(i+j)/2-i) //到中間都對-->迴文!!! 
				   {
				   	    if(max<=(j-i+1))//把比目前長的存下 
			            {
			            	max=j-i+1;
			               
					   	    b1[total]=i;
					   	    b2[total]=j;
					   	    
						   	    
				            num[total]=j-i+1;
				            total++;
						} 
			            
			            break; //比目前短的不儲存 
				   }
				   
		        }
			}	   
			
		
		if(max==0)	
			printf("0");
		else
		{
			printf("%d ",max);
		
		    for(i=0;i<total;i++)
			    if(num[i]==max)
			    {
			    	if(sum==0)
			    	{   
					    for(j=b1[i];j<=b2[i];j++)
					        printf("%c",a[j]);
			    	    sum=1; 
			    	}    
			    	else
					{
						printf(", ");
						for(j=b1[i];j<=b2[i];j++)
					        printf("%c",a[j]);
					}   
				       
			    }
		    
		}
		
		printf("\n");
	}
	
}
