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
		int outsurgery1=17000; //�w�q�~���N����
		int outsurgery2=13000; 
		int outsurgery3=15000; 
		int outsurgery4=16000; 
		int outsurgery5=14000; 
		
		int surgery1=31786;//�M�w�����N���O�� 
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
		
		int getpharcharge()//�~���N������
		{
			if(choose==0)
			{
				temp="No_surgery ";
				return 0; 
				break;
			}
			if(choose==1)
			{
				temp+="�@���G����_";
				return outsurgery1;
			}
			else if(choose==2)
			{
				temp+="����Ӽv_";
				return outsurgery2;
			}
			else if(choose==3)
			{
				temp+="���ƹD��N_";
				return outsurgery3;
			}
			else if(choose==4)
			{
				temp+="�c���D��N_";
				return outsurgery4;
			}
			else if(choose==5)
			{
				temp+="��G�z�R_";
				return outsurgery5;
			}
		} 
		
		int getSurgeryCharge()//�����N������ 
		{
			if(type==0)
			{
				temp1="No_Internal_Medicine ";
				return 0;
				break;
			}
			if(type==1)
			{
				temp1+="��ũʤf��_";
				return surgery1;
			}
			else if(type==2)
			{
				temp1+="�ͤ��~_";
				return surgery2;
			}
			else if(type==3)
			{
				temp1+="�߰I��_";
				return surgery3;
			}
			else if(type==4)
			{
				temp1+="�z���H����_";
				return surgery4;
			}
			else if(type==5) 
			{
				temp1+="�O�ک��x�ު�_";
				return surgery5;
			}
		}
		string rephar()//�~ 
		{
			return temp;
		}
		string reSurgery()//�� 
		{
			return temp1;
		}
		
		void outsurgery(Account &act) 
		{
			temp="";
			 
			cout<<"�п�J�~���N���ƶq(1~5)(������N�]�п�J1):";//���X�إ~���N 
			cin>>num;
			while(num > 5 && num < 1 && num==0 )
			{
				cout << "���~�A�Э��s��J: ";
				cin >> num;
			}
			
			cout<<"�п�J�~���N�۹������Ʀr (0)������N (1)�@���G���� (2)����Ӽv (3)���ƹD��N (4)�c���D��N (5)��G�z�R"<<endl;//�����ǥ~���N
			for(int i=1;i<=num;i++)
			{
				cout<<"��"<<i<<"�Ӥ�N:"; 
				cin>>choose;
				while(choose>5||choose<0)
				{
					cout<<"���~�A�Э��s��J:";
					cin>>choose;
				}
				act.GetCharge(getpharcharge());//���N�`���^�Ǩ�account�� 
			}
			
			
		}
		
		
		void surgery(Account &act)//���F������Ǥ�N 
		{		
			temp1="";
				
			cout << "�п�J�����N���ƶq(1~5)(������N�]�п�J1): ";
			cin >> num1;
			while(num1 > 5 && num1 < 1 && num1 == 0 )
			{
				cout << "���~�A�Э��s��J: ";
				cin >> num1;
			}		
			
			cout <<"�п�J�����N�۹������Ʀr (0)������N (1)��ũʤf�� (2)�ͤ��~ (3)�߰I�� (4)�z���H���� (5)�O�ک��x�ު�"<<endl;//�������п�J�۹������Ʀr(ex:��ũʤf���п�J1)
			for(int i = 1; i <= num1; i++)
			{
				cout<<"��"<<i<<"�Ӥ�N:";
				cin >> type;
				while(type<0 || type>5)
				{
					cout << "���~�A�Э��s��J: ";
					cin >> type;
				}
				act.GetCharge(getSurgeryCharge());//���N�`���^�Ǩ�account�� 
			}
							
			
			
		}    
};

#endif
