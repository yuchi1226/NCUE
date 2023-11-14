#include <iostream>
#include <iomanip>
#include "pub.h"
using namespace std;

void print(int type, Magazine m, Journal j, Book b)		//輸出使用者傳入的資料 
{
	if(type == 1)
	{
		cout << "----------Book----------" << endl;
		cout << "Title: " << b.gettitle() << endl;
		cout << "Volume: " << b.getvolume() << endl;
		cout << "Year: " << b.getyear() << endl;
		cout << "Author: " << b.getauthor() << endl;
		cout << "ISBN: " << b.getISBN() << endl;
		cout << "Price: " << b.getprice() << endl;
		cout << "------------------------" << endl;
	}
	else if(type == 2)
	{
		cout << "----------Journal----------" << endl;
		cout << "Title: " << j.gettitle() << endl;
		cout << "Volume: " << j.getvolume() << endl;
		cout << "Year: " << j.getyear() << endl;
		cout << "Month: " << j.getmonth() << endl;
		cout << "ISSN: " << j.getISSN() << endl;
		cout << "Impact Factor: " << j.getimpactFactor() << endl;
		cout << "Annual Subscription: " << j.getannualSubscription() << endl;
		cout << "---------------------------" << endl;
	}
	else if(type == 3)
	{
		cout << "----------Magazine----------" << endl;
		cout << "Title: " << m.gettitle() << endl;
		cout << "Volume: " << m.getvolume() << endl;
		cout << "Year: " << m.getyear() << endl;
		cout << "Month: " << m.getmonth() << endl;
		cout << "Editor: " << m.geteditor() << endl;
		cout << "Annual Subscription: " << m.getannualSubscription() << endl;
		cout << "----------------------------" << endl;
		
	}
}

void function(int menu, Magazine m, Journal j, Book b)
{
	if(menu == 1) // Book
	{
		cout << "Please input the information of the BOOK below: " << endl;
		
		string temp;
		int temp1;
		float temp2;
		
		cout << "(1/6)	Please input the Title: ";
		cin>>temp;
		b.settitle(temp);
		
		cout << "(2/6)	Please input the Volume(integer): ";
		cin>>temp1;
		b.setvolume(temp1);
		
		cout << "(3/6)	Please input the year(integer): ";
		cin>>temp1;
		b.setyear(temp1);
		
		cout << "(4/6)	Please input the author: ";
		cin>>temp;
		b.setauthor(temp);
		
		cout << "(5/6)	Please input the ISBN: ";
		cin>>temp;
		b.setISBN(temp);
		
		cout << "(6/6)	Please input the price(float): ";
		cin>>temp2;
		b.setprice(temp2);
		
		cout << "Information added!!" << endl;
	}
	else if(menu == 2)	//Journal
	{
		cout << "Please input the information of the JOURNAL below: " << endl;
		
		string temp;
		int temp1;
		float temp2;
		
		cout << "(1/7)	Please input the Title: ";
		cin>>temp;
		j.settitle(temp);
		
		cout << "(2/7)	Please input the Volume(integer): ";
		cin>>temp1;
		j.setvolume(temp1);
		
		cout << "(3/7)	Please input the year(integer): ";
		cin>>temp1;
		j.setyear(temp1);
		
		cout << "(4/7)	Please input the month(integer): ";
		cin>>temp1;
		j.setmonth(temp1);
		
		cout << "(5/7)	Please input the ISSN: ";
		cin>>temp;
		j.setISSN(temp);
		
		cout << "(6/7)	Please input the impact factor(float): ";
		cin>>temp2;
		j.setimpactFactor(temp2);
		
		cout << "(7/7)	Please input the annual subscription(integer): ";
		cin>>temp1;
		j.setannualSubscription(temp1);
		
		cout << "Information added!!" << endl;
	}
	else if(menu == 3)  //Magazine
	{
		cout << "Please input the information of the MAGAZINE below: " << endl;
		
		string temp;
		int temp1;
		float temp2;
		
		cout << "(1/6)	Please input the Title: ";
		cin>>temp;
		m.settitle(temp);
		
		cout << "(2/6)	Please input the Volume(integer): ";
		cin>>temp1;
		m.setvolume(temp1);
		
		cout << "(3/6)	Please input the year(integer): ";
		cin>>temp1;
		m.setyear(temp1);
		
		cout << "(4/6)	Please input the month(integer): ";
		cin>>temp1;
		m.setmonth(temp1);
		
		cout << "(5/6)	Please input the editor: ";
		cin>>temp;
		m.seteditor(temp);
		
		cout << "(6/6)	Please input the annual Subscription(integer): ";
		cin>>temp1;
		m.setannualSubscription(temp1);
		
		cout << "Information added!!" << endl;
	}
	print(menu, m, j, b);
}


int main()
{
	Book b;
	Journal j;
	Magazine m;
	
	int menu;
	
	do{
		
	 	do{
	 		
			cout << "What type of information are you adding?" << endl;
			cout << "(1) Book   (2) Journal   (3) Magazine   (4)End : ";
			cin >> menu;
			
			if(menu< 1 || menu > 4)
				cout << "Please input a valid number (1~4)." << endl;
			
		}while(menu > 4 || menu < 1);
		
		function(menu, m, j, b);
		
		cout<<" ";	
		
	}while(menu != 4) ;
	
	cout << "Have a nice day!!" << endl;
	return 0;
}





