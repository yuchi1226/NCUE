#include <iostream>
#include "Length.h"
#include "Rectangle.h"

using namespace std; 

void function( int func, Rectangle rec ,int length , int width)
{
	if(func == 1)
	{
		if(rec.isSquare())
			cout<<"\nIt is a square!\n\n";
		else
			cout<<"\nIt is not a square!\n\n"; 
	}
	else if(func == 2)
	{
		
		cout<<"\nlength:"<< length << " cm\n\n" ;
		cout<<"\nwidth:" << width << " cm\n\n" ;	
	
		cout<<"\nlength:"<< length*10 << " mm\n\n" ;
		cout<<"\nwidth:" << width*10 << " mm\n\n" ;		
		
	}
	else if(func == 3)
	{

			cout<<"\nArea:" << rec.getArea().getCentimeters() << " cm^2\n\n" ;

			cout<<"\nArea:" << 10*rec.getArea().getCentimeters() << " mm^2\n\n" ;
	}
	else if(func == 4)
	{
			cout << "\nPerimeter:" << rec.getPerimeter().getCentimeters() << " cm\n\n" ;
		
			cout << "\nPerimeter:" << 10*rec.getPerimeter().getCentimeters() << " mm\n\n" ;
	}
}

int main(int argc, char** argv) 
{
 
	Length a, b;
	Rectangle rec;
	int length,width;
	int func;
	
    do{
		
		cout << "Please input the length (cm): ";
		cin >> length;
		cout << "Please input the width (cm): ";
		cin >> width;
		a.setCentimeters(length);
		b.setCentimeters(width);
		rec.setSides(a,b);
		
		do
		{
			cout << "(1)Is is a square?"<<endl;
			cout << "(2)Get the sides."<<endl;
			cout << "(3)Get the area."<<endl;
			cout << "(4)Get the perimeter."<<endl; 
			cout << "(5)if you want to leave: ";
			cin >> func;
			
			if(func > 5 || func < 1)
				cout << "Please input a valid number." << endl << endl;
				
		}while(func > 5 || func < 1);
		
		function( func, rec, length, width);
	
	
	}while(func != 5) ;
	
	cout << "end!!!!." << endl << endl;
	
	return 0;
}




