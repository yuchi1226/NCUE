#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

int main()
{
	int i,j,len,n=0,count[100]={0};
	char word[100][20],input[20];
	
	FILE *DataIn;
	FILE *DataOut;	
	DataIn=fopen("t3.txt","r");
	DataOut=fopen("t4.txt","w");
	
	if(DataIn!=NULL && DataOut!=NULL)
	{
		while(fscanf(DataIn,"%s",input)==1)
		{
			len=strlen(input);
			
			if(input[len-1]==',' || input[len-1]=='.')
			   input[len-1]='\0';
			   
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
		
		
		
		for(j=0;j<n;j++)
		   fprintf(DataOut,"%s: %d\n",word[j],count[j]);
			
		
	}


    fclose(DataIn);
	fclose(DataOut);


}
