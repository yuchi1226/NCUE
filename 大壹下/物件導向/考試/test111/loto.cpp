#include <iostream>
#include "loto.h"

int rand(int **table,int num)
{
	int i,j,m,mark;
	
	for(m=0;m<num;m++)//看使用者想要幾組	
	{	
	    for(i=0;i<6;i++)//循環6次，生成6個字符密碼
		{
			mark=rand()%45+1;//產生從1到45共46個隨機數字 
			
			for(j=0;j<i;j++)
				if(table[m][i]==table[m][j])
			        break;
			if(j>=i)        
	            table[m][i]=mark;
	        else
			    continue;    
		}
	     
	}
}
void sort(int **table,int num)//從小排到大 
{
	int i,j,m,mark;
	
	for(m=0;m<num;m++)
		for (i=0;i<6;++i)
		    for (j=0;j<i;++j) 
			    if (table[m][j] > table[m][i]) 
				    swap(table[m][j], table[m][i]);
}
void loto()
{
	int num;
	srand(time(NULL));
	
	cout << "Please input sets of number to generate: ";
	cin >> num;
	
	int **table = new int *[num];
	for(int i = 0 ; i < num ; i++)
		table[i] = new int[6];
	
	rand(table, num);
	sort(table, num);
	
	for(int i = 0 ; i < num ; i++)
	{
		for(int j = 0 ; j < 6 ; j++)
			cout << table[i][j] << endl;
		cout << endl;
	}	
}
