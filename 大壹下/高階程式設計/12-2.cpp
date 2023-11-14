#include<stdio.h>
#include<string.h>
int main()
{
	char a[100000];
	
	while(gets(a))
	{ 
		int n,m,i,j,k;
		int count=0,max=0,r=0;
	   
	    int list[50000][2];
	    
	    n=strlen(a);
	    m=n-max/2;
	    
	    for(i=0;i<m;i++)
		{
			if(max/2>n-i)//剩下的文字比max還少就不用做了 
			 break;
			 
			if(a[i]==a[i+1])//偶數-->自身與(前OR後)一樣
			{
			   int n1,n2,len=2; 
			   n1=1;n2=i+1;
			   	
				while(a[i-n1]==a[n2+n1])
				{
					len+=2;
					n1++;
					if(i-n1<0||n2+n1>n)
					  break;
				}
				n1--;
			    if(max<len)
			    {
			    	max=len; m=n-max/2;
			    	list[0][0]=i-n1;
			    	list[0][1]=n2+n1;
			    	r=1;	
				}
				else if(max==len)
				{
					list[r][0]=i-n1;
			    	list[r][1]=n2+n1;
			    	r++;
				}
			}
			if(i>0&&a[i-1]==a[i+1])//單數-->中心點為對稱.前後一樣 
			{
				int n1=2,len=3;  
				while(a[i-n1]==a[i+n1])
				{
					len+=2;
				    n1++;  
					if(i-n1<0||i+n1>n)
					  break;		
				}
				n1--;
				if(max<len)
			    {
			    	max=len; 
					m=n-max/2;	
			    	list[0][0]=i-n1;
			    	list[0][1]=i+n1;
			    	r=1;	
				}
				else if(max==len)
				{
					list[r][0]=i-n1;
			    	list[r][1]=i+n1;
			    	r++;
				}
			}
		}
		
		
		if(max==1)
		    printf("%d\n",0);
		else
		{
			printf("%d ",max);
			
		    for(k=0;k<r;k++)
		    {
		        for(int g=list[k][0];g<=list[k][1];g++)
		            printf("%c",a[g]);
		        if(k!=r-1)
			        printf(", ");	
		    }
	
	    } 
	    
		printf("\n"); 
	} 
	return 0; 
}


