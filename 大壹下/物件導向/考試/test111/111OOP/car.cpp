#include <iostream>
#include <string>
#include "car.h"
using namespace std;

void Car::constructor(int y, string m)
{
	year = y;
	make = m;
	speed = 0;
}
int Car::getyear()	
{
	return year;
}
string Car::getmake()
{
	return make;
}
int Car::getspeed()
{
	return speed;
}
int Car::accelerate()
{
	return (speed+5);
}
int Car::brake()
{
	return (speed-5);
}

void Car::test()
{
		Car c;
		int y;
		string m;
		cout << "Please input the year the car was made: ";
		cin >> y;
		cout << "Please input the make of the car: ";
		cin >> m;
		c.constructor(y,m);
		cout << "Car Make: " << c.getmake() << "	Year made: " << c.getyear() <<endl;
		c.speed = c.accelerate();
		cout << "The car has speed up!"<< endl;
		cout << "Speed: " << c.getspeed() <<endl;
		c.speed = c.brake();
		cout << "The car has braked!" <<endl;
		cout << "Speed: " << c.getspeed() <<endl;
}
