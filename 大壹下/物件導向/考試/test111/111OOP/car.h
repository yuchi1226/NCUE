#include <iostream>
#include <string>
#ifndef CAR_H
#define CAR_H
using namespace std;

class Car
{
	private:
		int year;
		string make;
		int speed;
	public:
		void constructor(int, string); //constructor 
		int getyear();		
		string getmake();
		int getspeed();
		int accelerate();
		int brake();
		void test();
};
#endif
