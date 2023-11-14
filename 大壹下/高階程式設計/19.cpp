#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include<stdio.h>
#include <string.h>
using namespace std;

bool like[50][50] = {false};
bool visit[20];
int f_match[20];

bool match(int j, int female)
{
 	for(int i=0;i<female;i++)
 	{
 		if (like[i][j] == true && visit[i] == false)
 		{
 			visit[i] = true;
 			if(f_match[i] == -1 || match(f_match[i], female))
 			{
			 	f_match[i] = j;
 				return true;
 			}
		 }
    }
	return false;
}

int main()
{
	int num,//�X�����
		male,//�X�W�k�� 
		female;//�X�W�k�� 
	int i,j,k,n,m,temp;	
		
	cin>>num;

	for(i=0;i<num;i++)
	{	
		cin>>male>>female;
		
		int men[female][male],//�s�n�P�� 
			women[female][male];
		
			
		for( j = 0 ; j < male ; j ++)
		{	
			int binary[female];
			
			cin >> temp;
			for( k = 0 ; k < female ; k ++)
			{
				binary[k] = temp % 2;
				temp /= 2;
			}
			for( k = 0 ; k < female ; k ++)
			{
				men[k][j] = binary[k];
			}
		}//��k�n�P�צs�n
		
		for( j = 0 ; j < female ; j ++)
		{
			int binary1[male];
			
			cin >> temp;
			for( k = 0 ; k < male ; k ++)
			{
				binary1[k] = temp % 2;
				temp /= 2;
			}
			for( k = 0 ; k < male ; k ++)
			{
				women[j][k] = binary1[k];
			}
		}//��k�n�P�צs�n	
		
		for(j=0;j<female;j++)
			for(k=0;k<male;k ++)
				if(men[j][k]==1 && women[j][k]==1)
					like[j][k] = true;
				else
					like[j][k] = false;
						
	    int count = 0;
	    
	    for(j=0;j<20;j ++)
	    {
	    	visit[j] = false;
	    	f_match[j] = -1;
	    }
	    	
	    for(j=0;j<male;j++)
	    {
	    	for(k=0;k<20;k++)
	    		visit[k] = false;
	    	if(match(j,female) == true)
	    		count++;
	   	}
	    cout << (count * 10000) << endl;
		
		
	}//for end	
	
}
