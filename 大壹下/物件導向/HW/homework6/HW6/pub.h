#ifndef PUB_H
#define PUB_H

#include <string>
using namespace std;

class Publication
{
	public:
		string title;
		int volume;
		int year;
	public:	
		Publication()//constructor 
		{
			title = "";
			volume = 0;
			year = 0;
		}
		
		void settitle(string t)
		{title = t;}
		
		void setvolume(int v)
		{volume = v;}
		
		void setyear(int y)
		{year = y;}
		
		string gettitle()
	    {return title;}
	    
		int getvolume()
		{return volume;}
		
		int getyear()
		{return year;}
};

class Book:public Publication
{
	private:
		string author;
		string ISBN;
		float price;
	public:
		Book(): Publication()//constructor 
		{
			title = "";
			volume = 0;
			year = 0;
			author = "";
			ISBN = "";
			price = 0;
		}
		
		void setauthor(string au)
		{author = au;}
		
		void setISBN(string IS)
		{ISBN = IS;}
		
		void setprice(float p)
		{price = p;}
		
		string getauthor()
		{return author;}
		
		string getISBN()
		{return ISBN;}
		
		float getprice()
		{return price;}
		 
};

class Journal:public Publication
{
	private:
		int month;
		string ISSN;
		float impactFactor;
		int annualSubscription;
	public:
		Journal(): Publication()//constructor 
		{
			title = "";
			volume = 0;
			year = 0;
			month = 0;
			ISSN = "";
			impactFactor = 0;
			annualSubscription = 0;
		}
		
	    void setmonth(int m)
	    {month = m;}
	    
	    void setISSN(string IS)
	    {ISSN = IS;}
	    
		void setimpactFactor(float iF)
		{impactFactor = iF;}
		
		void setannualSubscription(int aS)
		{annualSubscription = aS;}
		
		int getmonth()
		{return month; }
		
		string getISSN()
		{return ISSN;}
		
		float getimpactFactor()
		{return impactFactor;}
		
		int getannualSubscription()
		{return annualSubscription;}
	 
	
};
 
class Magazine:public Publication 
{
	private:
		int month;
		string editor;
		int annualSubscription;
	public:
		Magazine() : Publication()//constructor 
		{
			title = "";
			volume = 0;
			year = 0;
			month = 0;
			editor = "";
			annualSubscription = 0;	
		}
		void setmonth(int m)
		{month = m;}
		
		void seteditor(string ed)
		{editor = ed;}
		
		void setannualSubscription(int aS)
		{annualSubscription = aS;}
		
		int getmonth()
		{return month; }
		
		string geteditor()
		{return editor;}
		
		int getannualSubscription()
		{return annualSubscription;}
};



#endif
