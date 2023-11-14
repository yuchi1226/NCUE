#include <iostream>
#include <string.h>
using namespace std;

void search_name();
void search_date();
void print(int);
void addquote();
void deletequote();

class Customer//顧客資料 
{
	private:
		string name;
		string address;
		string phone;
		
	public:
		void Name(string n)//名字 
		{name = n;}
		
		void Address(string a)//地址 
		{address = a;}
		
		void Phone(string p)//電話 
		{phone = p;}
		
		string getname()
		{return name;}
		
		string getaddress()
		{return address;}
		
		string getphone()
		{return phone;}
};

class Car//車子資料 
{
	private:
		string make;
		string model;
		int year;
		
	public:
		void Make(string m)//品牌 
		{make = m;}
		
		void Model(string m)//型號 
		{model = m;}
		
		void Year(int y)//出廠日期 
		{year = y;}
		
		string getmake()
		{return make;}
		string getmodel()
		{return model;}
		int getyear()
		{return year;}
};

class Quote//估價單 
{
	private:
		double parts;
		double labor;
		int date;
		
	public:
        
		void Parts(double p)//部分款項 
		{parts = p;}
		 
		void Labor(double l)// 仲介費 
		{labor = l;}
		
		void Date(int d)//交貨日期 
		{date = d;}
		
		double getparts()
		{return parts;}
		double getlabor()
		{return labor;}
		int getdate()
		{return date;}
		double gettotal()//總費用 
		{return (parts + labor);}
};

struct info
{
	class Customer cus;
	class Car c;
	class Quote q;
};

info info[100]; 
int count = 1;

int main() 
{

	int menu;
	char search;
	bool again=true;
	int again1 = 0;
	
	//內載範例//設為第一位客戶 
	info[0].cus.Address("Taiwan");
	info[0].cus.Name("vicky");
	info[0].cus.Phone("0912345678");
	info[0].c.Make("BMW");
	info[0].c.Model("Sport Convertible");
	info[0].c.Year(2020);
	info[0].q.Date(20210501);
	info[0].q.Labor(3000);
	info[0].q.Parts(1500);
	
	do{		
		cout <<"如要搜尋估價單，請按1\n";
		cout <<"如要新增估價單，請按2\n";
		cout <<"如要刪除估價單，請按3\n";
		cout <<"如要離開此系統，請按4: "; 
		cin >> menu;
		if(menu==1)
		{
	        cout<<"\n以客戶名字來搜尋，請按1\n"; 
			cout<<"以估價單日期來搜尋，請按2: ";
		    cin >> search;
		    switch(search)
		    {
			  	case '1': search_name();//以客戶名字來搜尋 
				  		break;
			  	case '2': search_date();//以交貨日期來搜尋 
				  		break;
		    }
		} 		    		    
		else if(menu==2)
		{
		    addquote(); 	
			break; 
		}			
		else if(menu==3)
		{
			deletequote();
			break;
		}	
		else if(menu==4)
		{
			again = false;
			break;
		}		    
		else	
		{
		    cout << "請輸入正確的值" << endl;
			again = true;
			break; 
					 
			cout << endl;			 
	    }
	    
	
	}while(again == true);
	
	cout << endl;
	cout << "end!" << endl;
	return 0;
}

void print(int i)//如果找到客戶就印出資料 
{
	cout << endl;
	cout << "-------------------------------------------" << endl;
	cout << "Service Quote #" <<i<< endl;
	cout << "name: "<< info[i].cus.getname() << endl;
	cout << "address: " << info[i].cus.getaddress() << endl;
	cout << "phone: " << info[i].cus.getphone() << endl;
	cout << "Make: " << info[i].c.getmake() << endl;
	cout << "Model: " << info[i].c.getmodel() << endl;
	cout << "Year: " << info[i].c.getyear() << endl;
	cout << "Parts charges: " << info[i].q.getparts() << endl;
	cout << "Labor charges: " << info[i].q.getlabor() << endl;
	cout << "Total charges: " << info[i].q.gettotal() << endl;
	cout << "-------------------------------------------" << endl;
	cout << endl;
}

void search_name()//以客戶名字來搜尋 
{
	char name[21];
	bool found = false;
	
	cout << "\n請輸入欲搜尋的客戶名字，(欲離開請輸入1): ";
	cin>>name;
	if(name == "1")
	{	cout << "Exited!" << endl;
		return;
	}
	else
	{
		for(int i=0;i<count;i++) 
		{
			if(info[i].cus.getname()==name)
			{
				found = true;
				print(i);//呼叫資料 
			}
		}
	}
	if(found == false)
	{
		cout << "目錄中無此客戶!" << endl;
		return;
	}
}

void search_date()//以交貨日期來搜尋 
{
	int date;
	bool found = false; 
	
	cout << "請輸入欲搜尋的交貨日期，(欲離開請輸入1): ";
	cin >> date;
	
	if(date==1)
	{	
	    cout << "Exited!" << endl;
		return;
	}
	else
	{
		for(int i=0;i<count;i++)
		{
			if(info[i].q.getdate()==date)
			{
				found = true;
				print(i);
			}
		}
	}
	if( found == false)
	{
		cout << "目錄中無此交貨日期!" << endl;
		return;
	}
}

void addquote()//新增資料 
{
	int num;
	string temp;
	int temp1;
	double temp2;
	
	cout << "欲新增資料請輸入任意數，欲離開請輸入1: ";
	cin >> num;
	if(num==1)
	{
		cout<<"Exited!"<<endl;
		return;
	}
	else
	{
		cout << "目前輸入的是第 #"<< count+1 <<"位客戶的資料"<< endl;
		cout << "請輸入名字: ";
	    cin.get();
	    getline(cin, temp);
	    info[count].cus.Name(temp);
		cout << "請輸入地址: ";
		getline(cin, temp);
		info[count].cus.Address(temp);
		cout << "請輸入電話號碼: ";
		getline(cin, temp);
		info[count].cus.Phone(temp);
		cout << "請輸入欲訂購的車子品牌: ";
		getline(cin, temp);
		info[count].c.Make(temp);
		cout << "請輸入欲訂購的車子型號: ";
		getline(cin, temp);
		info[count].c.Model(temp);
		cout << "請輸入欲訂購的車子的發行年份: ";
		cin >> temp1;
		info[count].c.Year(temp1);
		cout << "請輸入部分款項: ";
		cin >> temp2;
		info[count].q.Parts(temp2);
		cout << "請輸入仲介費: ";
		cin >> temp2;
		info[count].q.Labor(temp2);
		cout << "請輸入交貨日期: ";
		cin >> temp;
		info[count].q.Date(temp1);
		
		count ++;
		return;
	}
	 
}
	
void deletequote()//刪除資料 
{	
	string name;
	char date;
	int num;
	bool found = false;
	
	cout << "欲刪除資料請輸入任意數，欲離開請輸入1: ";
	cin >> num;
	if(num==1)
	{
		cout<<"Exited!"<<endl;
		return;
	}
	else
	{
		cout << "請輸入欲刪除的客戶名字: ";
		cin >> name;
		for(int i=0;i<count;i++)
		{
			if(info[i].cus.getname() == name)
			{
				cout << "Found!";
				info[i].c.Make("");
				info[i].c.Model("");
				info[i].c.Year(0);
				info[i].cus.Address("");
				info[i].cus.Name("");
				info[i].cus.Phone("");
				info[i].q.Date(0);
				info[i].q.Labor(0.0);
				info[i].q.Parts(0.0);
				cout << "Deleted!" << endl;
				found = true;
			}
		}
		if( found == false)
			cout << "Not Found!" << endl;
		return;

	}
}


	
