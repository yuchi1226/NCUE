#include <iostream>
#include "Length.h"
using namespace std;

class Rectangle
{
private:
	Length length;
	Length width;
public:
	void setSides(Length l, Length w)
	{
		length = l;
		width = w;
	}
	
	bool isSquare()
	{
		return length == width;
	}
	
	Length getArea()
	{
		return (length * width);
	}
	
	Length getPerimeter()
	{
		return (length + width + length + width);
	}
};
//type == 1: centimeter
//type == 2: millimeter
//get == 1: get length
//get == 2: get width
