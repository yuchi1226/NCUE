#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

int main()
{
	
	FILE *DataIn;
	FILE *DataOut;	
	
	DataIn=fopen("作業十附檔.txt","r");
	DataOut=fopen("作業十輸出.txt","w");
	
	int i,a,b,c,d,e,f,count=1,core=0;
	int score[31][4];
    char subject[3][5],name[30][20],ch;
    
	if(DataIn!=NULL && DataOut!=NULL)
	{
	
	while((ch=fgetc(DataIn))!='\n')
	    continue;
		    	
	for(i=0;i<30;i++)
	    fscanf(DataIn,"%s,%d,%*c%d,%*c%d",name[i],score[i][0],score[i][1],score[i][2]);
		
	for(a=0;a<3;a++)
	{
		int sum=0;
		
		for(b=0;b<30;b++)
			sum=sum+score[b][a];
		
		score[30][a]=sum/30;
	}   
	
	for(c=0;c<30;c++)
	   score[c][3]=score[c][0]+score[c][1]+score[c][2];
	   
	for(d=0;d<30;d++)
	{
		int max=30;
		
		for(e=0;e<30;e++)
		{
			if(score[e][3]>max)
			{
				max=score[e][3];
				core=e;
			}
		}
		
		score[e][3]=count;
		count++;
	}   
		

	fprintf(DataOut,"        國文 數學 英文 班排\n");	
	for(f=0;f<30;f++)
        fprintf(DataOut,"%s   %d   %d   %d   %d\n",name[f],score[f][0],score[f][1],score[f][2],score[f][3]);
    fprintf(DataOut,"平均     %d   %d   %d   ",score[30][0],score[30][1],score[30][2]);
	
	}
	
	fclose(DataIn);
	fclose(DataOut);
 
}
