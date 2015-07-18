#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int j =0;

class Demo
{
public:
	Demo():str(NULL)
	{
		cout <<"construction"<<endl;
	};
	~Demo()
	{
		if (str)
		{
			cout<<"deconstruction"<<j++<<endl;
			delete [] str;
		}
	};
	char *str;
	
};

int main(int argc, char const *argv[])
{
	Demo d1;
	d1.str = new char [32];
	strcpy(d1.str,"tremd mocro");

	vector<Demo> *a1 = new vector<Demo>();
	a1->push_back(d1);
	// delete a1;
	return 0;
}