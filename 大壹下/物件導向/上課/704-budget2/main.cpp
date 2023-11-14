#include <iostream>
#include <iomanip>
#include "budget2.h" // For Budget class declaration
using namespace std;

int main()
{
	const int N_DIVISIONS = 4;
	
	
	cout << "Enter the main office's budget request: ";
	double amount;
	cin >> amount;
	
	
	Budget divisions[N_DIVISIONS];
	divisions[0].mainOffice(amount);
	
	
	for (int count = 0; count < N_DIVISIONS; count++)
	{
		double bud;
		
		cout << "Enter the budget request for division "<< (count + 1) << ": ";
		cin >> bud;
		divisions[count].addBudget(bud);
	}
	
	cout << setprecision(2);
	cout<< showpoint << fixed;
	cout << "\nHere are the division budget requests:\n";
	
	for (int count = 0; count < N_DIVISIONS; count++)
	{
		cout << "\tDivision " << (count + 1) << "\t$ ";
		cout << divisions[count].getDivBudget() << endl;
	}
	
	cout << "Total Requests (including main office): $ ";
	cout << Budget::getCorpBudget() << endl;
	
	return 0;
}
