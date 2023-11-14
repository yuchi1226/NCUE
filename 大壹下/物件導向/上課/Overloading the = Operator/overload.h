#ifndef OVERLOAD_H
#define OVERLOAD_H

#include <iostream>
using namespace std;

class NumberArray
{
	private:
		double *aPtr;
		int arraySize;
		
	public:
		// Overloaded operator function
		void operator=(const NumberArray &right);
	
		// Constructors and other member functions
		NumberArray(const NumberArray &);
		
		NumberArray(int size, double value);
		
		~NumberArray() 
		{ if (arraySize > 0) delete [ ] aPtr; }
		
		void print() const;
		void setValue(double value);

};

#endif
