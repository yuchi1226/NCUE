//��u�@ �����o S0954024  
#include"Account.h"
#include<iostream>
using namespace std;

class Pharmacy
{
	private: 
		int cephalexin=170; //�w�q�Ī�����
		int mefenamicacid=130; 
		int acetaminophen=150; 
		int oxethazaine=160; 
		int fexofenadine=140;  
	public:
		int choose;
		int num;
		int getpharcharge()//�Ī�������-->3 
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
			cout<<"�п�J�ī~���ƶq(1~5):";//���X���Ī�-->1 
			cin>>num;
			while(num>5)
			{
				cout<<"���~�A�Э��s��J:";
				cin>>num;
			}
			cout<<"�п�J�ī~���W�� (1)cephalexin (2)mefenamic acid (3)acetaminophen (4)oxethazaine (5)fexofenadine"<<endl;//�������Ī�-->2 
			for(int i=0;i<num;i++)
			{
				cout<<"��"<<i+1<<"���ī~:"; 
				cin>>choose;
				while(choose>5||choose<1)
				{
					cout<<"���~�A�Э��s��J:";
					cin>>choose;
				}
				act.GetCharge(getpharcharge());//���Ī��`���^�Ǩ�account�� 
			}
		}
};

