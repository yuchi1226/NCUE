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
		string costname; // 主人的名字
	    string phone; // 主人的手機
	    string type; // 寵物類別
	    string petname; // 寵物的名字
			
	    string branch; // 分店號碼 
		string date; // 日期
		string id; // 員工id
		
		string shower;
		string trim;
		
		string surgical;
		string internal;
		
		string cost;//總花費 
};

/*long byteNum(int recNum)
{
	return sizeof(info) * recNum;
}

void showRec(info record)//如果找到客戶就印出資料//901
{
	cout << "客戶的名字 : ";
	cout << record.costname << endl;
	cout << "客戶的手機 : ";
	cout << record.phone << endl;
	cout << "寵物類別 : ";
	cout << record.type << endl;
	cout << "寵物的名字 : ";
	cout << record.petname << endl;
	
	cout << "分店號碼 : ";
	cout << record.branch << endl;
	cout << "日期 : ";
	cout << record.date << endl;
	cout << "員工id : ";
	cout << record.id << endl;
	
	cout << "是否需要洗澡 : ";
	cout << record.shower << endl;
	cout << "是否需要洗澡 : ";
	cout << record.trim << endl;
	
	cout << "外科項目 : ";
	cout << record.surgical << endl;
	cout << "內科項目 : ";
	cout << record.internal << endl;
	
	cout << "總花費 : ";
	cout << record.cost << endl;
	
	
} 
*/

addquote()//新增 
{
	string temp;
	int temp1;
	string temp2;
	info person;
	
	fstream outputFile("finalexam.txt", ios::app);
	
	cout << "目前輸入的是第 #"<< Count()+1 <<"位客戶的資料"<< endl;
	
	cout<<"請輸入客戶的名字 : ";
    cin>>temp; 
    person.costname=temp;
	cout<<"請輸入客戶的手機 :";
	cin>>temp; 
	person.phone=temp;
	cout<<"請輸入寵物類別 :";
	cin>>temp; 
	person.type=temp;
	cout<<"請輸入寵物的名字 :";
	cin>>temp; 
	person.petname=temp;
	
	cout<<"請輸入分店號碼 :";
	cin>>temp; 
	person.branch=temp;
	cout<<"請輸入日期 :";
	cin>>temp; 
	person.date=temp;
	cout<<"請輸入員工ID :";
	cin>>temp; 
	person.id=temp;
	
	o.surgery(a);//得到Surgery的費用加到account中 
	o.outsurgery(a);
	s.Shower(a);//得到Pharmacy的費用加到account中
	s.Trim(a);
	
	person.shower=s.reShower();
	person.trim=s.reTrim();
	
	person.surgical=o.rephar();
	person.internal=o.reSurgery();
	
	person.cost=a.totalsum();//最終sum 
	
	temp2=person.costname+" "+person.phone+" "+person.type+" "+person.petname+" "+person.branch+" "+person.date+" "+person.id+" "+person.shower+" "+person.trim+" "+person.surgical+" "+person.internal+" "+person.cost+"\n";
	
	outputFile<<temp2;

	outputFile.close();
	
	
}

searchquote()//查詢 
{
	string temp
		  ,temp1
		  ,temp2;
	info person;
	int i,num;
	bool found=false;
	
	fstream outputFile("finalexam.txt", ios::in );
	
	cout<<"請輸入欲查詢的客戶手機號碼 :";
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
		cout << "客戶的名字 : ";
		cout << person.costname << endl;
		cout << "客戶的手機 : ";
		cout << person.phone << endl;
		cout << "寵物類別 : ";
		cout << person.type << endl;
		cout << "寵物的名字 : ";
		cout << person.petname << endl;
		
		cout << "分店號碼 : ";
		cout << person.branch << endl;
		cout << "日期 : ";
		cout << person.date << endl;
		cout << "員工id : ";
		cout << person.id << endl;
		
		cout << "是否需要洗澡 : ";
		cout << person.shower << endl;
		cout << "是否需要洗澡 : ";
		cout << person.trim << endl;
		
		cout << "外科項目 : ";
		cout << person.surgical << endl;
		cout << "內科項目 : ";
		cout << person.internal << endl;
		
		cout << "總花費 : ";
		cout << person.cost << endl<< endl;
	}
	
	outputFile.close();
	
}

changequote()//修改 
{
	int name,c,i=0;
	string temp
		  ,temp1
		  ,temp2;
	info person;
	
	fstream outputFile("finalexam.txt", ios::in);
	
	cout<<"請輸入欲修改的客戶手機號碼 :";
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
		
		cout << "目前修改的是第 #"<< c+1 <<"位客戶的資料"<< endl;
	
		cout<<"請輸入客戶的名字 : ";
	    cin>>str[c][0]; 
		cout<<"請輸入客戶的手機 :";
		cin>>str[c][1]; 
		cout<<"請輸入寵物類別 :";
		cin>>str[c][2]; 
		cout<<"請輸入寵物的名字 :";
		cin>>str[c][3]; 
		
		cout<<"請輸入分店號碼 :";
		cin>>str[c][4]; 
		cout<<"請輸入日期 :";
		cin>>str[c][5]; 
		cout<<"請輸入員工ID :";
		cin>>str[c][6]; 
		
		o.surgery(a);//得到Surgery的費用加到account中 
		o.outsurgery(a);
		s.Shower(a);//得到Pharmacy的費用加到account中
		s.Trim(a);
		
		str[c][7]=s.reShower();
		str[c][8]=s.reTrim();
		
		str[c][9]=o.rephar();
		str[c][10]=o.reSurgery();
		
		str[c][11]=a.totalsum();//最終sum 
		
		
		
		
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

deletequote()//刪除 
{
	int name,c,i=0;
	string temp
		  ,temp1
		  ,temp2;
	info person;
	
	fstream outputFile("finalexam.txt", ios::in);
	
	cout<<"請輸入欲修改的客戶手機號碼 :";
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
 		
		cout<<"新增資料請按1"<<endl;
		cout<<"查詢資料請按2"<<endl;
		cout<<"修改資料請按3"<<endl;
		cout<<"刪除資料請按4"<<endl;
		cout<<"離開請按5 : "; 
		cin >> menu;
		
		if(menu==1)//新增 
		{
	    	addquote(); 
		} 		    		    
		else if(menu==2)//查詢 
		{
		    searchquote();
		}			
		else if(menu==3)//修改 
		{
			changequote();
		}	
		else if(menu==4)//刪除 
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


