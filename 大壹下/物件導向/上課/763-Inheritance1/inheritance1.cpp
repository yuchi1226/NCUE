#include "inheritance1.h"

 //*********************************************
 // Constructor for the Student class. *
 //*********************************************
 Student::Student(string sname, Discipline d, Person *adv)
 {
	 // Access the protected member name
	 name = sname;
	
	 // Access the other members
	 major = d;
	 advisor = adv;
 }
