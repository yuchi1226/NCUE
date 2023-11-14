//資工一 王郁琁 S0954024  
#include"Account.h"
#include<iostream>
using namespace std;

class Pharmacy
{
	private: 
		int cephalexin=170; //定義藥物價格
		int mefenamicacid=130; 
		int acetaminophen=150; 
		int oxethazaine=160; 
		int fexofenadine=140;  
	public:
		int choose;
		int num;
		int getpharcharge()//藥物的價格-->3 
		{
			if(choose==1)
				return cephalexin;
			else if(choose==2)
				return mefenamicacid;
			else if(choose==3)
				return acetaminophen;
			else if(choose==4)
				return oxethazaine;
			else if(choose==5)
				return fexofenadine;
		} 
		void choosephar(Account &act) 
		{
			cout<<"請輸入藥品的數量(1~5):";//有幾種藥物-->1 
			cin>>num;
			while(num>5)
			{
				cout<<"錯誤，請重新輸入:";
				cin>>num;
			}
			cout<<"請輸入藥品的名稱 (1)cephalexin (2)mefenamic acid (3)acetaminophen (4)oxethazaine (5)fexofenadine"<<endl;//有哪些藥物-->2 
			for(int i=0;i<num;i++)
			{
				cout<<"第"<<i+1<<"個藥品:"; 
				cin>>choose;
				while(choose>5||choose<1)
				{
					cout<<"錯誤，請重新輸入:";
					cin>>choose;
				}
				act.GetCharge(getpharcharge());//把藥物總價回傳到account裡 
			}
		}
};

