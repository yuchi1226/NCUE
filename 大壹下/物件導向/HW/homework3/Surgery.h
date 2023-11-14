//資工一 戴育琪 S0954016 
#include "Account.h"
#include <iostream>
#include <string.h>
using namespace std;

class Surgery
{
	private:
		int Surgery1=31786;//決定各手術之費用 
		int Surgery2=10078;
		int Surgery3=98626;
		int Surgery4=143124;
		int Surgery5=52094;				
	public:
		int type;
		int num;
		int getSurgeryCharge()//手術的價格 -->3
		{
			if(type==1)
				return Surgery1;
			else if(type==2)
				return Surgery2;
			else if(type==3)
				return Surgery3;
			else if(type==4)
				return Surgery4;
			else if(type==5) 
				return Surgery5;
		}
		int count()//做了幾種手術 -->1
		{
			
			cout << "請輸入手術的數量(1~5): ";
			cin >> num;
			while(num > 5)
			{
				cout << "錯誤，請重新輸入: ";
				cin >> num;
			}
			return num;
		}
		void surgery_type(Account &act)//做了哪些手術 -->2
		{			
			int num=count();						
			cout <<"請輸入手術的名稱 (1)瘜肉切除 (2)胃鏡檢查 (3)膽囊切除術 (4)結腸切除術 (5)甲狀腺切除術"<<endl;//有做的請輸入相對應的數字(ex:瘜肉切除請輸入1)
			for(int i = 1; i <= num; i++)
			{
				cout<<"第"<<i<<"個手術:";
				cin >> type;
				while(type<1 || type>5)
				{
					cout << "錯誤，請重新輸入: ";
					cin >> type;
				}
				act.GetCharge(getSurgeryCharge());//把手術總價回傳到account裡 
			}
			
			 
		}    
			
	
};

