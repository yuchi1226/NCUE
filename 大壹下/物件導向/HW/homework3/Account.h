//��u�@ ���|�X S0954016 
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
		int rate;//�f�г����� 
		int roomcharge;
		int choose;
		int sum;
	    void count()//�Ѽ� 
		{			
			cout<<"�п�J��|���Ѽ�:"; 
			cin>>day;
			totalsum(day);
		}
		void sevices()///�f��+�A�ȶO 
		{
			
			printf("�п�ܯf������ (1)Single room (2)Double room (3)Special ward):");//��H��Single room--2500//���H��Double room--1200//�S���f��Special ward--3900/�� 
		                                                                                   //�A�ȶO�Υ]�t�b�f�жO�� 
		    cin>>choose;
			while(choose>3||choose<1) 
			{
				cout << "���~�A�Э��s��J: ";
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
		void GetCharge(int charge)//�p�J��N�P�ī~��O 
		{
			sum+=charge;
		}
		void totalsum(int day)//�`�O�� 
		{
			sum += (day * getroomCharge());
			cout << "The total charge is " << sum << "\nThank you!";
		}
		
};

#endif
