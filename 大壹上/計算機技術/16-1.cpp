#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<math.h> 

char input[31];
int width,current=0,len,i;


int main()
{
	FILE *fin;
	FILE *fout;
	fin=fopen("t12.txt","r");
	fout=fopen("t13.txt","w");
	
	printf("the width of word wrap:");
	scanf("%d",&width);
	
	while(fscanf(fin,"%s",input)==1)
	{
	    len=strlen(input);

        if(current+len>width && current!=0 && current!=1)
        {
        	fprintf(fout,"\n");
        	current=0;
		}

        if(current+len<width)
        {
        	fprintf(fout,"%s ",input);
		    current=current+len+1;
		}
		
		else if(current+len==width)
        {
        	fprintf(fout,"%s\n ",input);
		    current=1;
		}
		
		else
		{
			for(i=0;i<width-current;i++)
			    fprintf(fout,"%c",input[i]);
			fprintf(fout,"\n");
			for(i=width-current;i<len;i++)
			    fprintf(fout,"%c",input[i]);
			fprintf(fout," ");  
			current=len-width+current+1;  
		}
		
	}
    
	fclose(fin);
	fclose(fout);
}
