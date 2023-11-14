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
		void GetCharge(int charge)//計入手術與藥品花費 
		{
			sum+=charge;
		}
		string totalsum()//總費用 
		{
			string s;
			stringstream ss(s);
			ss << sum;
			
			return ss.str();
			
		}
};

#endif
