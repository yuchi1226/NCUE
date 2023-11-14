#include <iostream>
#include <string>
using namespace std;

class Date
{
	int day, year,month;
	
	int personID; // ID of person whose birthday this is
	
	public:
		Date(int m, int d, int y, int id):
		month(m), day(d), year(y), personID(id)
		{
			cout << "Date-Of-Birth object for person "<< personID << " has been created.\n\n";
		}
		~Date()
		{
		 	cout << "Date-Of-Birth object for person "<< personID << " has been destroyed.\n\n";
		}
};

class Country
{
	string name;
	
	public:
		Country(string name) : name(name)
		{
			cout << "A Country object has been created.\n\n";
		}
		~Country()
		{
			cout << "A Country object has been destroyed.\n\n";
		}
};

class Person
{
	string name;
	int personID; // Person identification number (PID)
	
	Date dateOfBirth;//另一class的導數 
	Country *pCountry;//另一class的指標 
	
	public:
		Person(string name, int month, int day, int year, Country *pC):
		name(name),dateOfBirth(month, day, year, Person::uniquePersonID),personID(Person::uniquePersonID),pCountry(pC)
		{
			cout << "Person object "<< personID << " has been created.\n\n";
			Person::uniquePersonID ++;
		}
		~Person()
		{
			cout << "Person object "<< personID << " has been destroyed.\n\n";
		}
		static int uniquePersonID; // Used to generate PIDs
};

// Define the static class variable
int Person::uniquePersonID = 1;

int main()
{

	Country usa("USA");
	
	Person *p = new Person("Peter Lee", 1, 1, 1985, &usa);
	Person p1("Eva Gustafson", 5, 15, 1992, &usa);
	
	cout << "Now there are two people.\n\n";
	
	// Delete the first person
	delete p;
	
	cout << "Now there is only one.\n\n";
	
	// The second person will go out of scope when main returns
	return 0;
}
