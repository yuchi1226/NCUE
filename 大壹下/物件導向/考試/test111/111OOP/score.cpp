#include <iostream>
#include <algorithm> 
#include "score.h"
using namespace std;

int score::isvalid()
{
	int temp;
	cin >> temp; 
	if (temp >= 0)
		return temp;
	else
	{	cout << "Please input a valid score: ";
		return isvalid();
	}
}
void score::sort(int *score, int num)
{
	for(int i = 0 ; i < num ; i++)
		for(int j = i+1; j < num ; j++)
			{if(*(score+j) < *(score+i))
				swap(*(score+j), *(score+i));
			}
}

double score::average(int *score, int num)
{
	double avg;
	int sum;
	for(int i = 0 ; i < num ; i++)
		sum+=*(score+i);
	avg = (double)sum/num;
	return avg;
}

void score::score1()
{
	int *score;
	int num;
	double avg;
	cout << "Please input the amount of scores: ";
	cin >> num;
	score = new int[num];
	
	for(int i = 0 ; i < num ; i++)
	{
		score[i] = isvalid();
	}
	sort(score, num);
	avg = average(score, num);
	cout << "Sorted Scores: ";
	for(int i = 0 ; i < num ; i++)
		cout << *(score+i) << "  ";
	cout << endl;
	cout << "average = " << avg;
	delete [] score;
}
