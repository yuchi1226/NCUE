#ifndef PatientAccount_CPP
#define PatientAccount_CPP
#include <iostream>

using namespace std;

class PatientAccount										//�����f�H�b��|�����`��O 
{
	private:
		int DailyRate = 500;								//�C�骺�f�жO 
		
	public:
		int TotalCharge = 0;							//�`�}�P 
		void GetCharge(int charge)						//�p�J��O 
		{
			TotalCharge += charge;
		}
		void days(int day)								//�p��f���`�O�� 
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
