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
	cout << "物件導向程式設計期中上機考試" << endl;
	cout << "\t1. 樂透號碼產生器" << endl;
	cout << "\t2. 考試成績處理" << endl;
	cout << "\t3. 基本class應用" << endl;
	cout << "\t4. 離開本系統" << endl;
	
	while(num !=4)
	{
	cout << "請輸入選項: ";
	cin >> num; 
	
	if (num == 1)
		l.loto1();
	else if(num == 2)
		s.score1();
	else if(num == 3)
		c.test();
	}
}
