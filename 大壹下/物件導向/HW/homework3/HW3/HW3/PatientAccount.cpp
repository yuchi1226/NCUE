#ifndef PatientAccount_CPP
#define PatientAccount_CPP
#include <iostream>

using namespace std;

class PatientAccount										//紀錄病人在醫院中的總花費 
{
	private:
		int DailyRate = 500;								//每日的病房費 
		
	public:
		int TotalCharge = 0;							//總開銷 
		void GetCharge(int charge)						//計入花費 
		{
			TotalCharge += charge;
		}
		void days(int day)								//計算病房總費用 
		{
			TotalCharge += (day * DailyRate);
			cout << "The total charge is " << TotalCharge << "\nThank you!";
		}
		void count()
		{
			int day;
			cout << "Please input the number of days you spent in the hospital: ";
			cin >> day;
			days(day);
		}
};

#endif
