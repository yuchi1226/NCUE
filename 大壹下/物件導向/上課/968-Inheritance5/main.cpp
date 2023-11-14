#include <iostream>
#include "inheritance5.h"

using namespace std;

int main()
{
	
	Person *arr[5] =
	{
		new TFaculty("Indiana Jones", ARCHEOLOGY, "Dr."),
		new Student("Thomas Cruise", COMPUTER_SCIENCE, NULL),
		new Faculty("James Stock", BIOLOGY),
		new TFaculty("Sharon Rock", BIOLOGY, "Professor"),
		new TFaculty("Nicole Eweman", ARCHEOLOGY, "Dr.")
	};
	 
	for (int k = 0; k < 5; k++)
		cout << arr[k]->getName() << endl;

	return 0;
}
