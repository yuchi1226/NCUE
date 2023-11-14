#include <iostream>
#include <string>
//#include "car.h"
using namespace std;

void cartest()
{
		Car c;
		int y;
		string m;
		cout << "Please input the year the car was made: ";
		cin >> y;
		cout << "\nPlease input the make of the car: ";
		cin >> m;
		c.Car(y,m);
		cout << "Car Make: " << c.getmake() << "Year made: " << c.getyear() <<endl;
		c.accelerate();
		cout << "The car has speed up!"<< endl;
		cout << "Speed: " << c.getspeed() <<endl;
		c.brake();
		cout << "The car has braked!" <<endl;
		cout <<"Speed: " <<c.getspeed() <<endl;
}
