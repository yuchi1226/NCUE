#ifndef THISEXAMPLE_H
#define THISEXAMPLE_H

class Example
{
	int x;
	
	public:
		Example(int a)
		    { x = a;}
		void setValue(int);
		void printAddressAndValue();
};

#endif
