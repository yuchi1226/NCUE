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
		
		for(i=0;i<len-1;i++)//�q�Y�}�l 
		    for(j=len-1;j>i&&j-i+1>=max;j--)//�q����^�@�˪��r�� //�פ����:i,j�������פp��max 
		    {
			    
		    	if(a[i]!=a[j])
		    	   continue;
		    	else //�p�G��� 
				{
					for(k=1;k<=(i+j)/2-i;k++)//���줤���ݬO�_�@�� 
				   	    if(a[i+k]-a[j-k]!=0)
				   	        break;
				   
				   if(k>(i+j)/2-i) //�줤������-->�j��!!! 
				   {
				   	    if(max<=(j-i+1))//���ثe�����s�U 
			            {
			            	max=j-i+1;
			               
					   	    b1[total]=i;
					   	    b2[total]=j;
					   	    
						   	    
				            num[total]=j-i+1;
				            total++;
						} 
			            
			            break; //��ثe�u�����x�s 
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
