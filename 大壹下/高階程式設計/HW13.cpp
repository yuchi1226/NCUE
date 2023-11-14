#include <iostream>
#include <iomanip>
#include<stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

int main()
{
	int num;
	int i,j,k,r;
	cin >> num;
	for(int r = 0 ; r < num ; r++)
	{
		int n;
		cin >> n;//Τ碭计 
		
		int a[50];
		int max[50][50];
		int min[50][50];
		
		for( i = 0 ; i < n ; i++) 
			cin >> a[i];//盢计皚い 
			
		for(i = 0 ; i < n ; i++)
			for(j = 0 ; j < n ; j ++)
				if(j - i == 2)//ㄢ计ぇ丁 
				{
					max[i][j] = a[i] * a[i+1] * a[j];
					min[i][j] = a[i] * a[i+1] * a[j];
				}
				else//à0 
				{
					max[i][j] = 0;
					min[i][j] = 0;
				}
		
		for(i = 3 ; i < n ; i++)
			for(j = 0 ; j < n - 2 ; j++)
			{
				int max2 = 0;
				int min2 = 999999999;
		
				for(k = j + 1 ; k < j + i ; k++)
				{
					max[j][j+i] = max[j][k] + max[k][j+i] + a[j] * a[j+i] * a[k]; 
					min[j][j+i] = min[j][k] + min[k][j+i] + a[j] * a[j+i] * a[k];
					
					if(max[j][j+i] > max2)//т程 
						max2 = max[j][j+i];
					else
						max[j][j+i] = max2;
							
					if(min[j][j+i] < min2)//т程 
						min2 = min[j][j+i];
					else
						min[j][j+i] = min2;
				}
			}
			
		cout << max[0][n-1] << " " << min[0][n-1] << endl;
	}
	return 0;
}
