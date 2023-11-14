#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	ifstream inputFile;
	ifstream outputFile;
	
	string filename;
	char ch;
	
	cout << "Enter the filename: ";
	cin >> filename;
	
	inputFile.open(filename.c_str());
	outputFile.clear();
	
	if (inputFile.fail())
		cout << "The file was not found." << endl;
	else
	{
		while((ch=getchar())!=EOF)
		{
			if(ch=='\n')
				ch=' ';
			
			cout.put(ch);
			
		}
		
		inputFile.close();
		outputFile.close();
	}
	
	return 0;
}
