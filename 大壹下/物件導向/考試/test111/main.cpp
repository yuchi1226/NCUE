#include <iostream>
#include "loto.cpp"
#include "car.h"

using namespace std;

int main() 
{
	int num;
	
	cout << "1. loto" << endl;
	cout << "\n2. score" << endl;
	cout << "\n3. car" << endl;
	cout << "\n4. ���}���t��" << endl;
	
	cout << "�п�J�ﶵ: ";
	cin >> num; 
	
	if(num == 1)	loto();
	
	else	return 0;
	
	system("pause");
}
