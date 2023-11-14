#ifndef INHERITANCE_H
#define INHERITANCE_H

#include <string>
using namespace std;

enum Discipline { ARCHEOLOGY, BIOLOGY, COMPUTER_SCIENCE };
enum Classification { FRESHMAN, SOPHOMORE, JUNIOR, SENIOR };

class Person
{
	private:
		string name;
	public:
		Person() 
		{ setName(""); }
		
		Person(string pName) 
		{ setName(pName); }
		
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
		 void setMajor(Discipline d)
		 { major = d; }
		 
		 Discipline getMajor() const 
		 { return major; }
		 
		 void setAdvisor(Person *p) 
		 { advisor = p; }
		 
		 Person *getAdvisor() const 
		 { return advisor; }
 };

 class Faculty:public Person
 {
	 private:
	 	Discipline department;
	 public:
		 void setDepartment(Discipline d) 
		 { department = d; }
		 
		 Discipline getDepartment( ) 
		 { return department; }
 };

#endif
