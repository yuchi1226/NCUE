#include <iostream>
#include <string.h>
#include "PatientAccount.cpp"

using namespace std;

class Surgery{
	private:
		int Arthrosocopy = 200000;					// surgery type 1: Arthrosocopy
		int Circumcision = 300000;					// surgery type 2: Circumcision
		int Vasectomy = 500000;						// surgery type 3: Vasectomy
		int Hysterectomies = 700000;				// surgery type 4: Hysterectomies
		int Myomectomies = 900000;					// surgery type 5: Myomectomies
		
	public: 
		char type[100];
		int getSurgeryCharge()			//gets the charge depends on the type of surgury
		{
			if(!strcmp(type, "Arthrosocopy"))
				return Arthrosocopy;
			else if(!strcmp(type, "Circumcision"))
				return Circumcision;
			else if(!strcmp(type, "Vasectomy"))
				return Vasectomy;
			else if(!strcmp(type, "Hysterectomies"))
				return Hysterectomies;
			else
				return Myomectomies;
		}
		void surgery_type(PatientAccount &act)
		{
			cout << "Please input the type of surgery: ";
			cin >> type;
			while(strcmp(type, "Arthrosocopy") && strcmp(type, "Circumcision") && strcmp(type, "Vasectomy") &&
				  strcmp(type, "Hysterectomies") && strcmp(type, "Myomectomies"))
			{
				cout << "Error! Please reenter the type of surgery: ";
				cin >> type;
			}
			act.GetCharge(getSurgeryCharge());
		}
};
		
