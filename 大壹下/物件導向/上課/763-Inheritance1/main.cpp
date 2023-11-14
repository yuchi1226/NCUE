 #include "inheritance1.h"
 #include <iostream>
 using namespace std;

 // These arrays of string are used to print
 // values of enumerated types

 const string dName[] ={"Archeology", "Biology", "Computer Science"};

 const string cName[] ={"Freshman", "Sophomore", "Junior", "Senior"};

 int main()
 {
	 // Create Faculty and Student objects
	 Faculty f("Indiana Jones", ARCHEOLOGY);
	 Student s("Sean Bolster", ARCHEOLOGY, &f);
	 
	 cout << "Professor " << f.getName() << " teaches " << dName[f.getDepartment()] << ".\n" << endl;
	
	 // Get student's advisor
	 Person *pAdvisor = s.getAdvisor();
	 
	 cout << s.getName() <<"\'s advisor is "<< pAdvisor->getName() << ".\n";
	
	 return 0;
 }
