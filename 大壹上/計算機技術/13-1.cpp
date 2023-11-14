#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

int main()
{
	int i,j,h,k,len,n=0,count[100]={0},put;
	char word[100][20],input[20],temp[20];
	
	FILE *DataIn;
	FILE *DataOut;	
	DataIn=fopen("t5.txt","r");
	DataOut=fopen("t6.txt","w");
	
	if(DataIn!=NULL && DataOut!=NULL)
	{
		while(fscanf(DataIn,"%s",input)==1)
		{
			len=strlen(input);
			
			if(input[len-1]==',' || input[len-1]=='.')
			   input[len-1]='\0';
			   
			if(65<=(int)input[0] && (int)input[0]<=90)
			   input[0]=input[0]+32;   
			   
			for(i=0;i<n;i++)
				if(strcmp(input,word[i])==0)
				{
					count[i]++;
					break;
				}
			
			if(i>=n)
		    {
			    strcpy(word[n],input);
		        count[n]++;
			    n++;
		    }	 
		}
	
	
	    for(k=0;k<n;k++)	
		    for(h=0;h<n-1;h++)
			    if(strcmp(word[h],word[h+1])==1)
			    {
			    	strcpy(temp,word[h]);
				    strcpy(word[h],word[h+1]);
				    strcpy(word[h+1],temp);
				    
				    put=count[h];
				    count[h]=count[h+1];
					count[h+1]=put;
			    }
			
		
			
		
		for(j=0;j<n;j++)
		   fprintf(DataOut,"%s:%d\n",word[j],count[j]);
			
		
	}


    fclose(DataIn);
	fclose(DataOut);

}
