//資工一 戴育琪 S0954016 負責Account,Surgery
//資工一 王郁琁 S0954024 負責Pharmacy,main fuction(含debug)
//遇到的困難1.英文題目一開始誤解了題意 解決方法:多看了幾次並記錄下來，還問了同學
//2.出現蠻多宣告上的問題 解決方法:使用網路查詢，確認哪個要放在private/public
//3.最終的sum出不來 解決方法:逐行debug並修正 
#include <iostream>
#include <iomanip>
#include "Account.h"
#include "Surgery.h"
#include "Pharmacy.h"


using namespace std;


int main()
{
	
	Account act;
	Surgery sgy;
	Pharmacy pmy;
	sgy.surgery_type(act);//得到Surgery的費用加到account中 
	pmy.choosephar(act);//得到Pharmacy的費用加到account中
	act.sevices();//得到病房的單日價格 
	act.count();//輸出最終sum 
	return 0;
	
}
