#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "pet.h"
#include <iostream>
#include <iomanip>
#include <string.h>
#include <sstream>
using namespace std;

class Account
{
	protected:
		int sum=0;
	public:	
		void GetCharge(int charge)//�p�J��N�P�ī~��O 
		{
			sum+=charge;
		}
		string totalsum()//�`�O�� 
		{
			string s;
			stringstream ss(s);
			ss << sum;
			
			return ss.str();
			
		}
};

#endif
