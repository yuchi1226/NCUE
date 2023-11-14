//Made by 資工一 S0954007 林易鴻, S0954010 謝宥宣, S0954044 黃奕誠, S0954046 洪紹譯
// S0954007 林易鴻: main, S0954010 謝宥宣: pharmacy, S0954044 黃奕誠: surgery, S0954046 洪紹譯: patientaccount.
//遇到的困難: 1.英文題目在閱讀上會有一些困難。 解決方法:請英文較好的組員先翻譯題目後再分工討論。
//			  2. 

#include <iostream>
#include "PatientAccount.h"
#include "Surgery.h"
#include "Pharmacy.h"

using namespace std;

int main()
{
	PatientAccount act;
	Surgery sgy;
	pharmacy pmy;
	sgy.surgery_type(act);
	pmy.pharmacy_type(act);
	act.count();
	return 0;
}
