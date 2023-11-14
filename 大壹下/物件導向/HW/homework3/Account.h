//資工一 戴育琪 S0954016 
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
using namespace std;

class Account
{
	private:
		int singular=2500;
		int doublle=1200;
		int special=3900;
		 
	public:
		int day;
		int rate;//病房單日價格 
		int roomcharge;
		int choose;
		int sum;
	    void count()//天數 
		{			
			cout<<"請輸入住院的天數:"; 
			cin>>day;
			totalsum(day);
		}
		void sevices()///病房+服務費 
		{
			
			printf("請選擇病房類型 (1)Single room (2)Double room (3)Special ward):");//單人房Single room--2500//雙人房Double room--1200//特等病房Special ward--3900/天 
		                                                                                   //服務費用包含在病房費內 
		    cin>>choose;
			while(choose>3||choose<1) 
			{
				cout << "錯誤，請重新輸入: ";
				cin>>choose;
				
			}                                                                        
		}
		int getroomCharge()
		{
			if(choose==1) return (singular
			);
	        else if(choose==2) return (doublle);
	        else if(choose==3) return (special);      
		}
		void GetCharge(int charge)//計入手術與藥品花費 
		{
			sum+=charge;
		}
		void totalsum(int day)//總費用 
		{
			sum += (day * getroomCharge());
			cout << "The total charge is " << sum << "\nThank you!";
		}
		
};

#endif
