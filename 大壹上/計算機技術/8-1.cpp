#include<stdio.h> 
#include<stdlib.h> 

int main()
{
	long long int a,dec=0;
	int r=0,i=0,j=0,n=1,c;
	int hexi[17]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int count[7];
	
	printf("please input a decimal number:");
	scanf("%d",&a);
	
	if(a>=0)
	{
		do{               
           r = a%16;     
		   count[j] = r; 
           a = a/16;
           j++;
        
          }while(j<8);
		  
		  
	    i=count[7];
	    count[7]=count[6];
	    count[6]=i;
	
	    i=count[5];
	    count[5]=count[4];
	    count[4]=i;
	
	    i=count[3];
	    count[3]=count[2];
	    count[2]=i;
	
        i=count[1];
	    count[1]=count[0];
	    count[0]=i;
	
	
	    for(c=0;c<=7;c++)
	    {
		    dec=dec+n*(count[c]);
		    n=n*16;
		
	    }
	
		printf("%lld",dec);
	}
	
	
	if(a<0)
	{
		a=a*-1;
		
		do{               
           r = a%16;     
		   count[j] = r; 
           a = a/16;
           j++;
        
          }while(j<8);
          
          
		count[0]=15-count[0];
        count[1]=15-count[1];
        count[2]=15-count[2];		
		count[3]=15-count[3];
		count[4]=15-count[4];
		count[5]=15-count[5];
		count[7]=14-count[7];
		
		i=count[7];
	    count[7]=count[6];
	    count[6]=i;
	
	    i=count[5];
	    count[5]=count[4];
	    count[4]=i;
	
	    i=count[3];
	    count[3]=count[2];
	    count[2]=i;
	
        i=count[1];
	    count[1]=count[0];
	    count[0]=i;
	
	
	    for(c=0;c<=7;c++)
	    {
		    dec=dec+n*(count[c]);
		    n=n*16;
		
	    }
	
		printf("%lld",dec);
		
    }
		
		
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

