#ifndef SURGERY_H
#define SURGERY_H
#include "Account.h"
#include "pet.h"
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

class Surgery
{
	private:
		int shower=1350;
		int trim=1400;			
	public:
		string temp;
		string temp1;
		
		int getShowercharge()
		{
			if(temp=="Y")
			{
				return shower;
			}
			else
				return 0;
		} 
		string reShower()
		{
			return temp;
		}
		
		int getTrimcharge()
		{
			if(temp1=="Y")
			{
				return trim;
			}
			else
				return 0;
		} 
		string reTrim()
		{
			return temp1;
		}
		
		void Shower(Account &act)//洗澡
		{						
			cout << "有需要洗澡嗎?(Y/N): ";
			cin >> temp;
			
			act.GetCharge(getShowercharge());
		}    
		void Trim(Account &act)//修毛 
		{							
			cout << "有需要修毛嗎?(Y/N): ";
			cin >> temp1;
						
			act.GetCharge(getTrimcharge());	
		}    
		
		
	
};

#endif
