#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

int main()
{
	int a=0,e=0,i=0,o=0,u=0;
	char ch;
	
	FILE *DataIn;
	FILE *DataOut;	
	DataIn=fopen("t1.txt","r");
	DataOut=fopen("t2.txt","w");
	
	if(DataIn!=NULL && DataOut!=NULL)
	{
		while((ch=fgetc(DataIn))!=EOF)
		{
			if(ch=='a' || ch=='A')
			  a++;
			if(ch=='e' || ch=='E')
			  e++;  
			if(ch=='i' || ch=='I')
			  i++;  
			if(ch=='o' || ch=='O')
			  o++;  
			if(ch=='u' || ch=='U')
			  u++;  
			  
		}
		
		fprintf(DataOut,"  A  E  I  O  U\n");
		fprintf(DataOut," %d %d %d %d %d",a,e,i,o,u);
		
	}
	
	fclose(DataIn);
	fclose(DataOut);
}
