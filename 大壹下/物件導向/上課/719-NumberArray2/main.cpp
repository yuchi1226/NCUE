#include <iostream>
#include <iomanip>
#include "NumberArray2.h"

using namespace std;

int main()
{
	NumberArray first(3, 10.5);
	
	NumberArray second = first;
	
	cout << setprecision(2) << fixed << showpoint;
	cout << "Value stored in first object is ";
	first.print();
	cout << "\nValue stored in second object is ";
	second.print();
	cout << "\nOnly the value in second object will be changed.\n";
	
	second.setValue(20.5);
	
	cout << "Value stored in first object is ";
	first.print();
	cout << endl << "Value stored in second object is ";
	second.print();
	return 0;

}
