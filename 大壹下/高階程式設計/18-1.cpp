#include <iostream>
#include <string>

using namespace std;

int main()
{
	string formation;//輸入格式 
	cin >> formation;
	int num;
	cin >> num;
	
	int m = 0,n = 0,
		i,j,k,t;
	char str[num][50];		
	int len[50];
	bool type[num];//存type n or * 
	int length = formation.size();

	for( i = 0 ; i < length ; i ++)	
	{
		if(formation[i] == 'n')
		{
			type[m] = 1;//n=1
			len[m] = n;//存拆開的這塊有幾個字 
			m ++;
			n = 0;
		}
		else if(formation[i] == '*')
		{
			type[m] = 0;//*=0
			len[m] = n;	
			m ++;
			n = 0;
		}
		else if(formation[i] == '(' || formation[i] == ')') // skip
			continue;
		
		str[m][n] = formation[i];
		n ++;
		
	}

	int nn = 0, sn = 0;// n的字元數， *的字元數 
	for( i = 0 ; i < m ; i++)
	{
		if(type[i] == true)// n
			nn += len[i];
		else
			sn += len[i];
	}
		
	for( t = 0 ; t < num ; t++)//存測資 
	{
		string test;
		cin >> test;
		
		int length1 = test.size();
		int ss[m][length1];
		
		for( j = 0 ; j < m; j++)	
			for( k = 0 ; k < length1 ; k++)
				ss[j][k] = 0;
		
		for( i = 0 ; i < m; i ++)	
		{
			if(len[i] == 1) //猜開的這塊只有一個字 
			{
				for( j = 0 ; j < length1 ; j++)
				{
					if(str[i][0] == test[j])
						ss[i][j] = 1;
					else
						ss[i][j] = 0;
				}
			}
			else//拆開的這塊不只一個字 
			{
				for( j = 0 ; j < length1 ; j++)
				{
					k = len[i] - 1;
					
					if(str[i][k] == test[j])	
					{
						bool found = false;
						for(int x = 1 ; x < len[i] ; x ++)
						{
							if(str[i][k - x] != test[j - x] ||  k - x < 0 || j - x < 0)
							{
								found = true;
								break;
							}
						}
						if(found == false)
						{
							for(int x = 0 ; x < len[i] ; x ++)
								ss[i][j - x] = 1;
						}
						found = false;
					}
				}
			}
		}
	
		int n, s;
		bool f = false, f1 = false, f2 = false;
		for( i = 1 ; i < length1 ; i ++)//n
		{
			n = i;
			for( j = 0 ; j < length1 ; j ++)//*
			{
				s = j;
				if( n * nn + s * sn > length1 )
					break;
				else if( n * nn + s * sn < length1)
					continue;
				else
				{
					f1 = false;
					int index = 0, count = 0;
					for( k = 0 ; k < m ; k ++)
					{
						if(type[k] == 1)//n
						{
							for(int ii = 0 ; ii < n ; ii ++)	
							{
								for(int z = 0 ; z < len[k] ; z ++)	
								{
									if(ss[k][index] != 1)
									{
										f1 = true;
										break;
									}
									index ++;	
								}
							}
						}
						else//*
						{
							for(int ii = 0 ; ii < s ; ii ++)	
							{
								for(int z = 0 ; z < len[k] ; z ++)	
								{										
									if(ss[k][index] != 1)
									{
										f1 = true;
										break;
									}	
									index++;
								}
							}
						}
					}
					if(f1 == false)
					{
						cout << "Y " << i << " " << j << endl;
						f = true;
						f2 = true;
						break;
					}
				}
			}
		}
		if(f2 == false)
			cout << "N" << endl;
	}
	return 0;
}

