#include <stdio.h> 
#include <stdlib.h> 

int sort_fraction(int p1,int p2)
{
		  
    while(p1!=0 && p2!=0)
    {
    	if(p1>p2)
    	   p1=p1%p2;
    	else
		   p2=p2%p1;   
	}
	      
	return p1+p2;    
}

void swap_fraction(int (*arr)[2],int n)
{
	int i,j,temp1,temp2;

	for(i=1;i<=n-1;i++)	
	    for(j=0;j<n-1;j++)
			if((float)**(arr+j)/(*(*(arr+j)+1))>(float)**(arr+j+1)/(*(*(arr+j+1)+1)))
			{
				temp1=**(arr+j);
				temp2=(*(*(arr+j)+1));
				**(arr+j)=**(arr+j+1);
				(*(*(arr+j)+1))=(*(*(arr+j+1)+1));
				**(arr+j+1)=temp1;				
			    (*(*(arr+j+1)+1))=temp2;
			  								
			} 
				
}

int main()
{
	int n,i,j,count=0,arr[200][2],k;
	
	printf("please input a number:");
	scanf("%d",&n);
	
	for(i=2;i<=n;i++)
		for(j=1;j<=i;j++)    
			if(sort_fraction(i,j)==1)
			{
			    arr[count][0]=j;
			    arr[count][1]=i;
				count++;  
			}
	
	swap_fraction(arr,count);
	printf("0,");
	for(k=0;k<count;k++)	
		printf("%d/%d,",arr[k][0],arr[k][1]);	
	printf("1(total:%d)",count+2);
}
