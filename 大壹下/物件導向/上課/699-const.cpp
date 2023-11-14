#include <iostream>
using namespace std;
class K
{
	public:
		
		void output()const
		{cout << "Output of a K object" << endl;}
};

void outputFirst(const K arr[])
{
	arr[0].output();
}
int main(int argc, char** argv)
{
	K arr[] = { K() };
	outputFirst(arr);
	
	return 0;
}
