#ifndef LENGTH_H
#define LENGTH_H
#include <iostream>
using namespace std;

class Length
{
private:
	double centimeters;
public:
	Length(double cm = 0)
	{
		setCentimeters(cm);
	}
	void setCentimeters(double cm)
	{
		centimeters = cm;
	}
	
	double getCentimeters()
	{
		return centimeters;
	}
	
	Length operator+(Length a)
	{
		Length sum;
		sum.centimeters = this->centimeters + a.centimeters;
		return sum;
	}
	Length operator*(Length a)
	{
		Length prod;
		prod.centimeters = this->centimeters * a.centimeters;
		return prod;
	}
	bool operator==(Length a)
	{
		if(this->centimeters == a.centimeters)
			return true;
		else
			return false;
	}
};
#endif
