#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;

int main()
{
	int n,i,j;
	
	cin>>n;
	
	char animal[1000],place[1000];
	int number,num[n];
	char ani[n][1000],pla[n][1000];
	int total=0;
     

	
	
	
	for(i=0;i<n;i++)
	{
		scanf("%s%d%s",animal,&number,place);//輸入資料 
		
		for(j=0;j<total;j++)
		{
			if(strcmp(ani[j],animal)==0&&strcmp(pla[j],place)==0)//對比有沒有相同動物出現在相同地方 
			{
			    num[j]+=number;//有就加在一起 
			    break;
			}
		}
		
		if(j==total)//沒有就列為新資料 
		{
		    strcpy(ani[total],animal);
		    strcpy(pla[total],place);
		    num[total]=number;
		    total++;
		}
	}
	
	for(i=0;i<total;i++)
    {
		if(pla[i][0]!=' ')//第一個新地點 
		{
		    printf("%s : ",pla[i]);
		    printf("%s %d",ani[i],num[i]);
		    
		    for(j=i+1;j<total;j++)//將相同地點的開頭改成' '//就會被跳過 
			{
			    if(strcmp(pla[i],pla[j])==0)
				{
				    printf(", %s %d",ani[j],num[j]);
				    pla[j][0]=' ';
				}
			}
			
		    pla[i][0]=' ';
		    printf("\n");
		}
    }

	
	
}


