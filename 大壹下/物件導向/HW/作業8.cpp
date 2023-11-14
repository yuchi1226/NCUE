#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include <fstream>
using namespace std;

void addquote(fstream &);
void deletequote(fstream &);
void changequote(fstream &);

struct record
{
	string item;
	int quantity;
	int wholecost;
	int retailcost;
	string date;
	
}record[100]; 
int count=1;

long byteNum(int recNum)
{
	return sizeof(record) * recNum;
}

int main()
{

	fstream outputFile("outputFile.txt", ios::out | ios::binary);
	
	int menu;
	bool again=true;

	
	if (!outputFile)
	{
		cout << "Error opening file.";
		return 0;
	}
	while(again==true)
	{
		cout<<"�s�W��ƽЫ�1"<<endl;
		cout<<"�R����ƽЫ�2"<<endl;
		cout<<"���ܸ�ƽЫ�3"<<endl;
		cout<<"���}�Ы�4 : "; cin>>menu; 
		
		if(menu==1)
		{
			addquote(outputFile); 	
			break; 
		}
		else if(menu==2)
		{
			deletequote(outputFile);
			break;
		}
		else if(menu==3)
		{
			changequote(outputFile);
		}
		else if(menu==4)
		{
			again=false;
			cout<<"\nHave a nice day\n";
			outputFile.close();
			break;
		}
		else
		{
			while(0<menu && menu<5)
			{
				cout<<"Please input a useful number(1~4) :";
				cin>>menu;
			}
		}
		 
	}
	
	
	
}

void addquote(fstream &outputFile)//�s�W��� 
{
	string temp;
	int temp1;

		
	cout << "�ثe��J���O�� #"<< count <<"��Ȥ᪺���"<< endl;
	
	cout<<"intput the item :";
    cin>>temp; 
    record[count].item=temp;
	cout<<"intput the quantity :";
	cin>>temp1; 
	record[count].quantity=temp1;
	cout<<"intput the wholecost :";
	cin>>temp1; 
	record[count].wholecost=temp1;
	cout<<"intput the retailcost :";
	cin>>temp1; 
	record[count].retailcost=temp1;
	cout<<"intput the date :";
	cin>>temp; 
	record[count].date=temp;
	
	outputFile.seekg(byteNum(count), ios::beg);
	outputFile.write(reinterpret_cast<char *>(&record),sizeof(record));

	count ++;
	return;
	
}

void deletequote(fstream &outputFile)//�R����� 
{	
	
	int n;
 	string temp=0;
	
	
	cout << "�п�J���R�����O�ĴX�����: ";
	cin >> n;
	
	if(n<0 || n>count)
	{
		while(n<0 || n>count)
		{
			cout<<"Please input a useful number :";
			cin>>n;
		}
	} 
	
	if(0<n|| count>=n)
	{
		record[n].item=temp;
		record[n].quantity=0;
		record[n].wholecost=0;
		record[n].retailcost=0;
		record[n].date=temp;
		
		outputFile.seekg(byteNum(n), ios::beg);
		outputFile.write(reinterpret_cast<char *>(&record),sizeof(record));
	
		cout << "Deleted!" << endl;
		
	}
	
	return;

	
}

void changequote(fstream &outputFile)//�s�W��� 
{
	int n;
	string temp;
	int temp1;
		
	cout << "�п�J�����ܪ��O�ĴX�����: ";
	cin >> n;
	
	cout<<"intput the item :";
    cin>>temp; 
    record[n].item=temp;
	cout<<"intput the quantity :";
	cin>>temp1; 
	record[n].quantity=temp1;
	cout<<"intput the wholecost :";
	cin>>temp1; 
	record[n].wholecost=temp1;
	cout<<"intput the retailcost :";
	cin>>temp1; 
	record[n].retailcost=temp1;
	cout<<"intput the date :";
	cin>>temp; 
	record[n].date=temp;
	
	outputFile.seekg(byteNum(n), ios::beg);
	outputFile.write(reinterpret_cast<char *>(&record),sizeof(record));
	
	cout<<"changed!"<< endl;
	return;
	
}


