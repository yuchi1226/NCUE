#ifndef INHERITANCE1_H
#define INHERITANCE1_H

#include <string>
#include <iostream>
using namespace std;

 enum Discipline { ARCHEOLOGY, BIOLOGY, COMPUTER_SCIENCE };
 enum Classification { Freshman, Sophomore, Junior, Senior };

 class Person
 {
	 protected:
	 	string name;
	 public:
		 Person() 
		 { setName("");}
		 
		 Person(string pName) 
		 { setName(pName);}
		 
		 void setName(string pName) 
		 { name = pName; }
		 
		 string getName() const 
		 { return name; }
 };

 class Student:public Person
 {
	 private:
		 Discipline major;
		 Person *advisor;
	
	 public:
		 // Constructor
		 Student(string sname, Discipline d, Person *adv);
	
		 void setMajor(Discipline d) 
		 { major = d; }
		 
		 Discipline getMajor() const 
		 {return major; }
		 
		 void setAdvisor(Person *p)
		 {advisor = p;}
		 
		 Person *getAdvisor() const 
		 { return advisor; }
 };

 class Faculty:public Person
 {
	 private:
	 	Discipline department;
	 	
	 public:
	 // Constructor
	 Faculty(string fname, Discipline d)
	 {
		 // Access the protected base class member
		 name = fname;
		 department = d;
	 }
	 
	 // Other member functions
	 void setDepartment(Discipline d) 
	 { department = d; }
	 
	 Discipline getDepartment( ) const 
	 { return department; }
 };

#endif
