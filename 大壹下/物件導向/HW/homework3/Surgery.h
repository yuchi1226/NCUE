//��u�@ ���|�X S0954016 
#include "Account.h"
#include <iostream>
#include <string.h>
using namespace std;

class Surgery
{
	private:
		int Surgery1=31786;//�M�w�U��N���O�� 
		int Surgery2=10078;
		int Surgery3=98626;
		int Surgery4=143124;
		int Surgery5=52094;				
	public:
		int type;
		int num;
		int getSurgeryCharge()//��N������ -->3
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
		int count()//���F�X�ؤ�N -->1
		{
			
			cout << "�п�J��N���ƶq(1~5): ";
			cin >> num;
			while(num > 5)
			{
				cout << "���~�A�Э��s��J: ";
				cin >> num;
			}
			return num;
		}
		void surgery_type(Account &act)//���F���Ǥ�N -->2
		{			
			int num=count();						
			cout <<"�п�J��N���W�� (1)泦פ��� (2)�G���ˬd (3)�x�n�����N (4)���z�����N (5)�Ҫ��������N"<<endl;//�������п�J�۹������Ʀr(ex:泦פ����п�J1)
			for(int i = 1; i <= num; i++)
			{
				cout<<"��"<<i<<"�Ӥ�N:";
				cin >> type;
				while(type<1 || type>5)
				{
					cout << "���~�A�Э��s��J: ";
					cin >> type;
				}
				act.GetCharge(getSurgeryCharge());//���N�`���^�Ǩ�account�� 
			}
			
			 
		}    
			
	
};

