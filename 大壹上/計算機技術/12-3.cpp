#include<stdio.h> 
#include<stdlib.h> 

int main()
{
	int a,b,c;
	int h,count=0;
	
	for(a=10;a<=99;a++)
	{
	   for(b=100;b<=999;b++)
	   {
	   	    c=a*b;
	   	    
	   	    if(c>9999 && c<100000)
	   	    {
	   	    	int number[10]={0},u=0;
	   	    	
	   	    	number[a/10]++; 
	   	    	number[a%10]++; 
	   	    	number[b/100]++; 
	   	    	number[b/10-((b/100)*10)]++; 
	   	    	number[b%10]++; 
	   	    	number[c/10000]++; 
	   	    	number[c/1000-((c/10000)*10)]++; 
	   	    	number[c/100-((c/1000)*10)]++; 
	   	    	number[c/10-((c/100)*10)]++; 
	   	    	number[c%10]++; 
				   
	   	    	for(h=0;h<=10;h++)
                {
	               if(number[h]==1)
	                  u++; 
					else  
					  break;      
	            }
    
	            if(u==10)
	            {
	            	count++; 
	            	printf("%d*%d=%d\n",a,b,c);
				}    
       
			}

	   }
	}   
	   printf("%d¦¸",count);
	   
}
