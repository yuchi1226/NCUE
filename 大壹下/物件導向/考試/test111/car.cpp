#include <iostream>
#include <string>
#include "car.h"
using namespace std;

void car::constructor(int y, string m)
{
	year = y;
	make = m;
	speed = 0;
}
int car::getyear()	
{
	return year;
}
string car::getmake()
{
	return make;
}
int car::getspeed()
{
	return speed;
}
int car::accelerate()
{
	return (speed+5);
}
int car::brake()
{
	return (speed-5);
}

void test()
{
	car c;
	
	int y;
	string m;
	cout << "Please input the year the car was made: ";
	cin >> y;
	cout << "\nPlease input the make of the car: ";
	cin >> m;
	c.constructor(y,m);
	
	cout << "Car Make: " << c.getmake() << "Year made: " << c.getyear() <<endl;
	
	cout << "The car has speed up!"<< endl;
	cout << "Speed: " <<c.accelerate() <<endl;
	
	cout << "The car has braked!" <<endl;
	cout <<"Speed: " <<c.brake() <<endl;
}
