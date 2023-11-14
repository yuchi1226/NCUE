#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
using namespace std;
#include "pet.h"
#include "Account.h"
#include "Surgery.h"
#include "Outsurgery.h"

Account a;
Surgery s;
Outsurgery o;

int Count()
{
	int count;
	string temp1;
	
	fstream outputFile("finalexam.txt", ios::in);
	
	while(outputFile>>temp1)
	{
		count++;			
	}
	
	count/=11;
	
	return count;
}

struct info
{
		string costname; // �D�H���W�r
	    string phone; // �D�H�����
	    string type; // �d�����O
	    string petname; // �d�����W�r
			
	    string branch; // �������X 
		string date; // ���
		string id; // ���uid
		
		string shower;
		string trim;
		
		string surgical;
		string internal;
		
		string cost;//�`��O 
};

/*long byteNum(int recNum)
{
	return sizeof(info) * recNum;
}

void showRec(info record)//�p�G���Ȥ�N�L�X���//901
{
	cout << "�Ȥ᪺�W�r : ";
	cout << record.costname << endl;
	cout << "�Ȥ᪺��� : ";
	cout << record.phone << endl;
	cout << "�d�����O : ";
	cout << record.type << endl;
	cout << "�d�����W�r : ";
	cout << record.petname << endl;
	
	cout << "�������X : ";
	cout << record.branch << endl;
	cout << "��� : ";
	cout << record.date << endl;
	cout << "���uid : ";
	cout << record.id << endl;
	
	cout << "�O�_�ݭn�~�� : ";
	cout << record.shower << endl;
	cout << "�O�_�ݭn�~�� : ";
	cout << record.trim << endl;
	
	cout << "�~�춵�� : ";
	cout << record.surgical << endl;
	cout << "���춵�� : ";
	cout << record.internal << endl;
	
	cout << "�`��O : ";
	cout << record.cost << endl;
	
	
} 
*/

addquote()//�s�W 
{
	string temp;
	int temp1;
	string temp2;
	info person;
	
	fstream outputFile("finalexam.txt", ios::app);
	
	cout << "�ثe��J���O�� #"<< Count()+1 <<"��Ȥ᪺���"<< endl;
	
	cout<<"�п�J�Ȥ᪺�W�r : ";
    cin>>temp; 
    person.costname=temp;
	cout<<"�п�J�Ȥ᪺��� :";
	cin>>temp; 
	person.phone=temp;
	cout<<"�п�J�d�����O :";
	cin>>temp; 
	person.type=temp;
	cout<<"�п�J�d�����W�r :";
	cin>>temp; 
	person.petname=temp;
	
	cout<<"�п�J�������X :";
	cin>>temp; 
	person.branch=temp;
	cout<<"�п�J��� :";
	cin>>temp; 
	person.date=temp;
	cout<<"�п�J���uID :";
	cin>>temp; 
	person.id=temp;
	
	o.surgery(a);//�o��Surgery���O�Υ[��account�� 
	o.outsurgery(a);
	s.Shower(a);//�o��Pharmacy���O�Υ[��account��
	s.Trim(a);
	
	person.shower=s.reShower();
	person.trim=s.reTrim();
	
	person.surgical=o.rephar();
	person.internal=o.reSurgery();
	
	person.cost=a.totalsum();//�̲�sum 
	
	temp2=person.costname+" "+person.phone+" "+person.type+" "+person.petname+" "+person.branch+" "+person.date+" "+person.id+" "+person.shower+" "+person.trim+" "+person.surgical+" "+person.internal+" "+person.cost+"\n";
	
	outputFile<<temp2;

	outputFile.close();
	
	
}

searchquote()//�d�� 
{
	string temp
		  ,temp1
		  ,temp2;
	info person;
	int i,num;
	bool found=false;
	
	fstream outputFile("finalexam.txt", ios::in );
	
	cout<<"�п�J���d�ߪ��Ȥ������X :";
	cin>>temp;
	
	while(outputFile>>temp1)
	{
		if(temp1==temp)
		{
			person.costname=temp2;
			person.phone=temp1;
			
			outputFile>>person.type;
			outputFile>>person.petname;
			outputFile>>person.branch;
			outputFile>>person.date;
			outputFile>>person.id;
			outputFile>>person.shower;
			outputFile>>person.trim;
			outputFile>>person.surgical;
			outputFile>>person.internal;
			outputFile>>person.cost;
			cout<<"found!!"<<endl;
			found=true;
			break;
		}
		temp2=temp1;	
	}	
	if(found==false)
	{
		cout<<"Not found!!"<<endl<< endl;
	}
	else
	{
		cout << "�Ȥ᪺�W�r : ";
		cout << person.costname << endl;
		cout << "�Ȥ᪺��� : ";
		cout << person.phone << endl;
		cout << "�d�����O : ";
		cout << person.type << endl;
		cout << "�d�����W�r : ";
		cout << person.petname << endl;
		
		cout << "�������X : ";
		cout << person.branch << endl;
		cout << "��� : ";
		cout << person.date << endl;
		cout << "���uid : ";
		cout << person.id << endl;
		
		cout << "�O�_�ݭn�~�� : ";
		cout << person.shower << endl;
		cout << "�O�_�ݭn�~�� : ";
		cout << person.trim << endl;
		
		cout << "�~�춵�� : ";
		cout << person.surgical << endl;
		cout << "���춵�� : ";
		cout << person.internal << endl;
		
		cout << "�`��O : ";
		cout << person.cost << endl<< endl;
	}
	
	outputFile.close();
	
}

changequote()//�ק� 
{
	int name,c,i=0;
	string temp
		  ,temp1
		  ,temp2;
	info person;
	
	fstream outputFile("finalexam.txt", ios::in);
	
	cout<<"�п�J���ק諸�Ȥ������X :";
	cin>>temp;
	
	string str[50][12];
	
	
	bool pointer=true,
		 found=false;
		 
	while(1)
	{
		for(int j=0;j<12;j++)
		{
			if(outputFile>>str[i][j])
			{
				if(str[i][j]==temp)
				{
					found=true;
					c=i;
				}
				if(j==11)
					i++;
				
			}
			else
			{
				pointer=false;
				break;
			}
		}
		if(pointer==false)
			break;
		
	}
	
	outputFile.close();
			
		
	if(found==true)
	{
		cout<<"found!!\n";
		
		cout << "�ثe�ק諸�O�� #"<< c+1 <<"��Ȥ᪺���"<< endl;
	
		cout<<"�п�J�Ȥ᪺�W�r : ";
	    cin>>str[c][0]; 
		cout<<"�п�J�Ȥ᪺��� :";
		cin>>str[c][1]; 
		cout<<"�п�J�d�����O :";
		cin>>str[c][2]; 
		cout<<"�п�J�d�����W�r :";
		cin>>str[c][3]; 
		
		cout<<"�п�J�������X :";
		cin>>str[c][4]; 
		cout<<"�п�J��� :";
		cin>>str[c][5]; 
		cout<<"�п�J���uID :";
		cin>>str[c][6]; 
		
		o.surgery(a);//�o��Surgery���O�Υ[��account�� 
		o.outsurgery(a);
		s.Shower(a);//�o��Pharmacy���O�Υ[��account��
		s.Trim(a);
		
		str[c][7]=s.reShower();
		str[c][8]=s.reTrim();
		
		str[c][9]=o.rephar();
		str[c][10]=o.reSurgery();
		
		str[c][11]=a.totalsum();//�̲�sum 
		
		
		
		
		fstream outputFile1("finalexam.txt", ios::out);
		
		for(i=0;i<=Count()+1;i++)
		{
			temp2=str[i][0]+" "+str[i][1]+" "+str[i][2]+" "+str[i][3]+" "+str[i][4]+" "+str[i][5]+" "+str[i][6]+" "+str[i][7]+" "+str[i][8]+" "+str[i][9]+" "+str[i][10];
			outputFile1<<temp2<<" "<<str[i][11]<<"\n";
		}
		
		outputFile1.close();
			
	}
	else
		cout<<"Not found!!\n\n";
	
	

}	

deletequote()//�R�� 
{
	int name,c,i=0;
	string temp
		  ,temp1
		  ,temp2;
	info person;
	
	fstream outputFile("finalexam.txt", ios::in);
	
	cout<<"�п�J���ק諸�Ȥ������X :";
	cin>>temp;
	
	string str[50][12];
	
	
	bool pointer=true,
		 found=false;
		 
	while(1)
	{
		for(int j=0;j<12;j++)
		{
			if(outputFile>>str[i][j])
			{
				if(str[i][j]==temp)
				{
					found=true;
					c=i;
				}
				if(j==11)
					i++;
				
			}
			else
			{
				pointer=false;
				break;
			}
		}
		if(pointer==false)
			break;
		
	}
	
	outputFile.close();
			
		
	if(found==true)
	{
		cout<<"found!!\n";
		

	    str[c][0]="";
		str[c][1]=""; 
		str[c][2]=""; 
		str[c][3]=""; 
		str[c][4]=""; 
		str[c][5]=""; 
		str[c][6]=""; 
		str[c][7]="";
		str[c][8]="";
		str[c][9]="";
		str[c][10]="";
		str[c][11]="";
		
		
		
		
		fstream outputFile1("finalexam.txt", ios::out);
		
		for(i=0;i<=Count()+1;i++)
		{
			temp2=str[i][0]+" "+str[i][1]+" "+str[i][2]+" "+str[i][3]+" "+str[i][4]+" "+str[i][5]+" "+str[i][6]+" "+str[i][7]+" "+str[i][8]+" "+str[i][9]+" "+str[i][10];
			outputFile1<<temp2<<" "<<str[i][11]<<"\n";
		}
		
		cout<<"Delet!!" <<endl;
		
		outputFile1.close();
			
	}
	else
		cout<<"Not found!!\n\n";
	
	
	
	
}



int main()
{
	bool again=true;
	int menu;
	info person;

 	do{
 		
		cout<<"�s�W��ƽЫ�1"<<endl;
		cout<<"�d�߸�ƽЫ�2"<<endl;
		cout<<"�ק��ƽЫ�3"<<endl;
		cout<<"�R����ƽЫ�4"<<endl;
		cout<<"���}�Ы�5 : "; 
		cin >> menu;
		
		if(menu==1)//�s�W 
		{
	    	addquote(); 
		} 		    		    
		else if(menu==2)//�d�� 
		{
		    searchquote();
		}			
		else if(menu==3)//�ק� 
		{
			changequote();
		}	
		else if(menu==4)//�R�� 
		{
			deletequote();
		}	
		else if(menu==5)
		{
			again = false;
		}		    
		else if(menu< 1 || menu > 5)
			cout << "Please input a valid number (1~5)." << endl;
		
	}while(again == true);
	
	cout<<endl;	
	
	cout << "END!!" << endl;
	
	
	return 0;

	
	
}


