#include <iostream>
#include <string>
#include "inheritance.h"

using namespace std;

// These arrays of string are used to print the
// enumerated types.
const string dName[] = {"Archeology", "Biology", "Computer Science"};
const string cName[] = {"Freshman", "Sophomore", "Junior", "Senior"};

int main()
{
	// Create a Faculty object
	Faculty f;
	
	// Use a Person member function
	f.setName("Indiana Jones");
	
	// Use a Faculty member function
	f.setDepartment(ARCHEOLOGY);
	
	cout << "Professor " << f.getName()<< " teaches in the Department of ";
	
	// Get department as an enumerated type
	Discipline dept = f.getDepartment();
	
	// Print out the department in string form
	cout << dName[dept] << endl;
	
	return 0;
}

while(again==true)
{ }
