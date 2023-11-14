#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include<stdio.h>
#include <string>
using namespace std;

int M[50][50];
int label_x[50];
int label_y[50];
int match_x[50];
int match_y[50];
bool visited_x[50];
bool visited_y[50]; 
const int inf = 1000000000;


bool DFS(int x,int m) 
{
	visited_x[x] = true;
	for (int i = 0; i < m; ++ i)
	if (!visited_y[i]) 
	{
		if (label_x[x] + label_y[i] == M[x][i]) 
		{
			visited_y[i] = true;
			if (match_y[i] == -1 || DFS(match_y[i],m))
			{
				match_x[x] = i; match_y[i] = x;
				return true;
			}
		}
	}
	return false;
}
int solution_c(int m) 
{
	int solution = 0;
	
	for (int i = 0; i < m; ++ i) 
	{ label_y[i] = 0; } /*�@�}�l�k�ͪ��t��ȬO 0 */
	
	for (int i = 0; i < m; ++ i) 
	{
		for (int j = 0; j < m; ++ j) 
		{
			if (M[i][j] != 1000000000) 
			{
				label_x[i] = std::max(label_x[i], M[i][j]);
				/*�@�}�l�k�ͪ��t��ȬO�C�@�C���̤j�� */
			}
		}
	}
	
	for (int x = 0; x < m; ++ x) 
	{
		match_x[x] = -1; /*�@�}�l�k�ͳ��٥��t�� */
		match_y[x] = -1; /*�@�}�l�k�ͳ��٥��t�� */
	}
	
	for (int x = 0; x < m; ++ x) 
	{
		while (true) 
		{
			for (int i = 0; i < m; ++ i) 
			{
				visited_x[i] = false;
				visited_y[i] = false;
			}
			
			if (DFS(x,m)) 
			{
				break; /* �{���q�B�z���k�ͥi�H���̨Ω��� */
			}
			
			int difference = inf;
			
			for (int x = 0; x < m; ++ x) 
			{
				if (visited_x[x]) 
				{
					for (int y = 0; y < m; ++ y) 
					{
						if (!visited_y[y]) 
						{
							if (M[x][y] != inf) 
							{difference = std::min(difference, label_x[x] + label_y[y] - M[x][y]);}
						}
					}
				}
			}
			/* ��X�o�@���Ҧ��������k�ͤ��i�H�Q�խ��̤֪��v���� */
			if (difference == inf) 
			{return -inf;}
			
			for (int x = 0; x < m; ++ x) 
			{
				if (visited_x[x]) 
				{label_x[x] -= difference;}
			} /* �N�o�@���Ҧ����Q���X�쪺�k���v�حȴ�h difference */
			
			for (int y = 0; y < m; ++ y)
			{
				if (visited_y[y]) 
				{label_y[y] += difference;} /* �N�o�@���Ҧ����Q���X�쪺�k���v�حȥ[�W difference */
			}
		}
	}
	
	for (int x = 0; x < m; ++ x) 
	{solution += M[x][match_x[x]];}
	
	return solution;
}


int main()
{
	int num,i,j,k,m;
	cin>>num;
	
	for(i=0;i<num;i++)
	{
		cin>>m;
		
		for(j=0;j<m;j++)
			for(k=0;k<m;k++)
				cin>>M[j][k];//�n�P�צs�n
				
		int max=0,sum=0,p1,p2,p3;
		for(j=0;j<m;j++)
		{
		 	max=0; 
			for(k=0;k<m;k++)
			{
				if(M[j][k]>max)
					max=M[j][k];
			}
			sum+=max;
		}
		p1=sum;
		sum=0;
		
		for(k=0;k<m;k++)
		{
		 	max=0; 
			for(j=0;j<m;j++)
			{
				if(M[j][k]>max)
					max=M[j][k];
			}
			sum+=max;
		}
		p2=sum;
		sum=0;	
		
		cout<<p1<<" "<<p2<<" "<<solution_c(m)<<endl;		
		
		
		
			 
	}//for end
}
