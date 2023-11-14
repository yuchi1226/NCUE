#ifndef OUTSURGERY_H
#define OUTSURGERY_H
#include "Account.h"
#include "pet.h"
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

class Outsurgery
{
	private: 
		int outsurgery1=17000; //定義外科手術價格
		int outsurgery2=13000; 
		int outsurgery3=15000; 
		int outsurgery4=16000; 
		int outsurgery5=14000; 
		
		int surgery1=31786;//決定內科手術之費用 
		int surgery2=10078;
		int surgery3=98626;
		int surgery4=143124;
		int surgery5=52094;	 
	public:
		int choose;
		int num;
		int num1;
		int type;
		string temp;
		string temp1;
		
		int getpharcharge()//外科手術的價格
		{
			if(choose==0)
			{
				temp="No_surgery ";
				return 0; 
				break;
			}
			if(choose==1)
			{
				temp+="一般血液檢驗_";
				return outsurgery1;
			}
			else if(choose==2)
			{
				temp+="脊髓照影_";
				return outsurgery2;
			}
			else if(choose==3)
			{
				temp+="消化道手術_";
				return outsurgery3;
			}
			else if(choose==4)
			{
				temp+="泌尿道手術_";
				return outsurgery4;
			}
			else if(choose==5)
			{
				temp+="血液透析_";
				return outsurgery5;
			}
		} 
		
		int getSurgeryCharge()//內科手術的價格 
		{
			if(type==0)
			{
				temp1="No_Internal_Medicine ";
				return 0;
				break;
			}
			if(type==1)
			{
				temp1+="潰瘍性口炎_";
				return surgery1;
			}
			else if(type==2)
			{
				temp1+="肺水腫_";
				return surgery2;
			}
			else if(type==3)
			{
				temp1+="心衰竭_";
				return surgery3;
			}
			else if(type==4)
			{
				temp1+="腸內寄生蟲_";
				return surgery4;
			}
			else if(type==5) 
			{
				temp1+="淋巴性膽管炎_";
				return surgery5;
			}
		}
		string rephar()//外 
		{
			return temp;
		}
		string reSurgery()//內 
		{
			return temp1;
		}
		
		void outsurgery(Account &act) 
		{
			temp="";
			 
			cout<<"請輸入外科手術的數量(1~5)(不做手術也請輸入1):";//有幾種外科手術 
			cin>>num;
			while(num > 5 && num < 1 && num==0 )
			{
				cout << "錯誤，請重新輸入: ";
				cin >> num;
			}
			
			cout<<"請輸入外科手術相對應的數字 (0)不做手術 (1)一般血液檢驗 (2)脊髓照影 (3)消化道手術 (4)泌尿道手術 (5)血液透析"<<endl;//有哪些外科手術
			for(int i=1;i<=num;i++)
			{
				cout<<"第"<<i<<"個手術:"; 
				cin>>choose;
				while(choose>5||choose<0)
				{
					cout<<"錯誤，請重新輸入:";
					cin>>choose;
				}
				act.GetCharge(getpharcharge());//把手術總價回傳到account裡 
			}
			
			
		}
		
		
		void surgery(Account &act)//做了內科哪些手術 
		{		
			temp1="";
				
			cout << "請輸入內科手術的數量(1~5)(不做手術也請輸入1): ";
			cin >> num1;
			while(num1 > 5 && num1 < 1 && num1 == 0 )
			{
				cout << "錯誤，請重新輸入: ";
				cin >> num1;
			}		
			
			cout <<"請輸入內科手術相對應的數字 (0)不做手術 (1)潰瘍性口炎 (2)肺水腫 (3)心衰竭 (4)腸內寄生蟲 (5)淋巴性膽管炎"<<endl;//有做的請輸入相對應的數字(ex:潰瘍性口炎請輸入1)
			for(int i = 1; i <= num1; i++)
			{
				cout<<"第"<<i<<"個手術:";
				cin >> type;
				while(type<0 || type>5)
				{
					cout << "錯誤，請重新輸入: ";
					cin >> type;
				}
				act.GetCharge(getSurgeryCharge());//把手術總價回傳到account裡 
			}
							
			
			
		}    
};

#endif
