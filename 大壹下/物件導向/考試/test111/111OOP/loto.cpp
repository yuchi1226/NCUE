#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include "loto.h"
using namespace std;

int loto::isvalid(int **table, int  i, int j)
	{
		int a = rand()%(45)+1;
		for(int k = 0 ; k < j ; k++)
				if(table[i][k] == a) 		//same
					return isvalid(table, i, j);
		return a;
	}
	
int loto::generate(int **table, int num)
	{
		for(int i = 0 ; i < num ; i++)
			for(int j = 0 ; j < 6 ; j++)
			{
				table[i][j] = isvalid(table, i, j);
			}
	}
void loto::sort(int ** table, int num)
	{
		for(int k=0; k< num; k++)
			for(int i = 0 ; i < 6 ; i++)
				for(int j = i + 1 ; j < 6 ; j++)
					if(table[k][j] < table[k][i])
						swap(table[k][j], table[k][i]);
	}
void loto::loto1()
	{
		int num;
		srand(time(NULL));
		cout << "Please input sets of number to generate: ";
		cin >> num;
		int **table = new int *[num];
		for(int i = 0 ; i < num ; i++)
			table[i] = new int[6];
		
		generate(table, num);
		sort(table, num);
		
		for(int i = 0 ; i < num ; i++)
		{
			for(int j = 0 ; j < 6 ; j++)
				cout << table[i][j] << " \t";
			cout << endl;
		}	
	}
