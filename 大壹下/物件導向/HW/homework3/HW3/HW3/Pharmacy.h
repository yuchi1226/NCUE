#include <iostream>
#include <string.h>
#include "PatientAccount.h"

using namespace std;

class pharmacy{										// Made by ¸ê¤u¤@ ÁÂ«É«Å S0954010 
	private:
		int Vicodin = 10000;						// Pharmacy type 1: Vicodin
		int Simvastatin = 30000;					// Pharmacy type 2: Simvastatin
		int Lisinopril = 50000;						// Pharmacy type 3: Lisinopril
		int Levothyroxine = 70000; 					// Pharmacy type 4: Levothyroxine
		int Lipitor = 90000;						// Pharmacy type 5: Lipitor
		
	public:
		char type[100];
		int getPharmacyCharge()			//gets the charge depends on the type of pharmacy
		{
			if(!strcmp(type, "Simvastatin"))
				return Simvastatin;
			else if(!strcmp(type, "Lisinopril"))
				return Lisinopril;
			else if(!strcmp(type, "Levothyroxine"))
				return Levothyroxine;
			else if(!strcmp(type, "Vicodin"))
				return Vicodin;
			else 
				return Lipitor;
		}
		void pharmacy_type(PatientAccount &act)
		{
			int num = count();
			for(int i = 0; i < num; i++)
			{
				cout << "Please input pharmacy" << i + 1 <<": ";
				cin >> type;
				while(strcmp(type, "Simvastatin") && strcmp(type, "Lisinopril") && strcmp(type, "Levothyroxine") &&
					  strcmp(type, "Vicodin") && strcmp(type, "Lipitor"))
				{
					cout << "Error! Please reenter the type of pharmacy: ";
					cin >> type;
				}
				act.GetCharge(getPharmacyCharge());
			}
		}
		int count()
		{
			int num;
			cout << "Please input the amount of medication (1~5):  ";
			cin >> num;
			while(num > 5)
			{
				cout << "Error! Please reenter the number of medication: ";
				cin >> num;
			}
			return num;
		}
};
