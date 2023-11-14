#include <iostream>
#include <string.h>
using namespace std;

void search_name();
void search_date();
void print(int);
void addquote();
void deletequote();

class Customer//�U�ȸ�� 
{
	private:
		string name;
		string address;
		string phone;
		
	public:
		void Name(string n)//�W�r 
		{name = n;}
		
		void Address(string a)//�a�} 
		{address = a;}
		
		void Phone(string p)//�q�� 
		{phone = p;}
		
		string getname()
		{return name;}
		
		string getaddress()
		{return address;}
		
		string getphone()
		{return phone;}
};

class Car//���l��� 
{
	private:
		string make;
		string model;
		int year;
		
	public:
		void Make(string m)//�~�P 
		{make = m;}
		
		void Model(string m)//���� 
		{model = m;}
		
		void Year(int y)//�X�t��� 
		{year = y;}
		
		string getmake()
		{return make;}
		string getmodel()
		{return model;}
		int getyear()
		{return year;}
};

class Quote//������ 
{
	private:
		double parts;
		double labor;
		int date;
		
	public:
        
		void Parts(double p)//�����ڶ� 
		{parts = p;}
		 
		void Labor(double l)// �򤶶O 
		{labor = l;}
		
		void Date(int d)//��f��� 
		{date = d;}
		
		double getparts()
		{return parts;}
		double getlabor()
		{return labor;}
		int getdate()
		{return date;}
		double gettotal()//�`�O�� 
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
	
	//�����d��//�]���Ĥ@��Ȥ� 
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
		cout <<"�p�n�j�M������A�Ы�1\n";
		cout <<"�p�n�s�W������A�Ы�2\n";
		cout <<"�p�n�R��������A�Ы�3\n";
		cout <<"�p�n���}���t�ΡA�Ы�4: "; 
		cin >> menu;
		if(menu==1)
		{
	        cout<<"\n�H�Ȥ�W�r�ӷj�M�A�Ы�1\n"; 
			cout<<"�H���������ӷj�M�A�Ы�2: ";
		    cin >> search;
		    switch(search)
		    {
			  	case '1': search_name();//�H�Ȥ�W�r�ӷj�M 
				  		break;
			  	case '2': search_date();//�H��f����ӷj�M 
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
		    cout << "�п�J���T����" << endl;
			again = true;
			break; 
					 
			cout << endl;			 
	    }
	    
	
	}while(again == true);
	
	cout << endl;
	cout << "end!" << endl;
	return 0;
}

void print(int i)//�p�G���Ȥ�N�L�X��� 
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

void search_name()//�H�Ȥ�W�r�ӷj�M 
{
	char name[21];
	bool found = false;
	
	cout << "\n�п�J���j�M���Ȥ�W�r�A(�����}�п�J1): ";
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
				print(i);//�I�s��� 
			}
		}
	}
	if(found == false)
	{
		cout << "�ؿ����L���Ȥ�!" << endl;
		return;
	}
}

void search_date()//�H��f����ӷj�M 
{
	int date;
	bool found = false; 
	
	cout << "�п�J���j�M����f����A(�����}�п�J1): ";
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
		cout << "�ؿ����L����f���!" << endl;
		return;
	}
}

void addquote()//�s�W��� 
{
	int num;
	string temp;
	int temp1;
	double temp2;
	
	cout << "���s�W��ƽп�J���N�ơA�����}�п�J1: ";
	cin >> num;
	if(num==1)
	{
		cout<<"Exited!"<<endl;
		return;
	}
	else
	{
		cout << "�ثe��J���O�� #"<< count+1 <<"��Ȥ᪺���"<< endl;
		cout << "�п�J�W�r: ";
	    cin.get();
	    getline(cin, temp);
	    info[count].cus.Name(temp);
		cout << "�п�J�a�}: ";
		getline(cin, temp);
		info[count].cus.Address(temp);
		cout << "�п�J�q�ܸ��X: ";
		getline(cin, temp);
		info[count].cus.Phone(temp);
		cout << "�п�J���q�ʪ����l�~�P: ";
		getline(cin, temp);
		info[count].c.Make(temp);
		cout << "�п�J���q�ʪ����l����: ";
		getline(cin, temp);
		info[count].c.Model(temp);
		cout << "�п�J���q�ʪ����l���o��~��: ";
		cin >> temp1;
		info[count].c.Year(temp1);
		cout << "�п�J�����ڶ�: ";
		cin >> temp2;
		info[count].q.Parts(temp2);
		cout << "�п�J�򤶶O: ";
		cin >> temp2;
		info[count].q.Labor(temp2);
		cout << "�п�J��f���: ";
		cin >> temp;
		info[count].q.Date(temp1);
		
		count ++;
		return;
	}
	 
}
	
void deletequote()//�R����� 
{	
	string name;
	char date;
	int num;
	bool found = false;
	
	cout << "���R����ƽп�J���N�ơA�����}�п�J1: ";
	cin >> num;
	if(num==1)
	{
		cout<<"Exited!"<<endl;
		return;
	}
	else
	{
		cout << "�п�J���R�����Ȥ�W�r: ";
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


	
