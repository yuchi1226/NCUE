#include <iostream>
#include "car.h"
#include "loto.h"
#include "score.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	Car c;
	loto l;
	score s;
	int num = 0;
	cout << "����ɦV�{���]�p�����W���Ҹ�" << endl;
	cout << "\t1. �ֳz���X���;�" << endl;
	cout << "\t2. �Ҹզ��Z�B�z" << endl;
	cout << "\t3. ��class����" << endl;
	cout << "\t4. ���}���t��" << endl;
	
	while(num !=4)
	{
	cout << "�п�J�ﶵ: ";
	cin >> num; 
	
	if (num == 1)
		l.loto1();
	else if(num == 2)
		s.score1();
	else if(num == 3)
		c.test();
	}
}
