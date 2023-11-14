#ifndef CAR_H
#define CAR_H
#include <string>
using namespace std;

class car
{
	public:
		void constructor(int year,string make);
		int getyear();
		string getmake();
		int getspeed();
		int accelerate();
		int brake();
		void test();
	protected:
		int year;
		string make;
		int speed;
};

#endif
