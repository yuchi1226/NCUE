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
		scanf("%s%d%s",animal,&number,place);//��J��� 
		
		for(j=0;j<total;j++)
		{
			if(strcmp(ani[j],animal)==0&&strcmp(pla[j],place)==0)//��񦳨S���ۦP�ʪ��X�{�b�ۦP�a�� 
			{
			    num[j]+=number;//���N�[�b�@�_ 
			    break;
			}
		}
		
		if(j==total)//�S���N�C���s��� 
		{
		    strcpy(ani[total],animal);
		    strcpy(pla[total],place);
		    num[total]=number;
		    total++;
		}
	}
	
	for(i=0;i<total;i++)
    {
		if(pla[i][0]!=' ')//�Ĥ@�ӷs�a�I 
		{
		    printf("%s : ",pla[i]);
		    printf("%s %d",ani[i],num[i]);
		    
		    for(j=i+1;j<total;j++)//�N�ۦP�a�I���}�Y�令' '//�N�|�Q���L 
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


