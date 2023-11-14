#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 

int main()
{
	int i,j,max=0,line,sum,a,code=0;
	int arr[30]={0},pair[30][30]={0},count[435][2];
	
	FILE *DataIn;	
	DataIn=fopen("t9.txt","r");
	
if(DataIn!=NULL)
{	
	fscanf(DataIn,"%d",&sum);
	
	for(a=0;a<sum;a++)
    {
    	fscanf(DataIn,"%d",&line);
    	for(i=0;i<line;i++)
			fscanf(DataIn,"%d",&arr[i]);
	    
	    for(i=0;i<line-1;i++)
	    	for(j=i+1;j<line;j++)
	    	    pair[arr[i]-1][arr[j]-1]++;
			 	
	}
	
	for(i=0;i<29;i++)
	    for(j=i+1;j<30;j++)
		{
			if(pair[i][j]>max)
			{
				max=pair[i][j];
				count[0][0]=i+1;
				count[0][1]=j+1;
				code=1;
			}
			
			else if(pair[i][j]==max)
			{
				count[code][0]=i+1;
				count[code][1]=j+1;
				code++;
			}
			
		}	
	
	for(i=0;i<code;i++)
	    printf("(%d,%d) %d¦¸\n",count[i][0],count[i][1],max);
	
}
	
	fclose(DataIn);
	
}
