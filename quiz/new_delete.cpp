#include <iostream>

using namespace std;

class MyClass
{
public:
	MyClass()
	{
		cout<<"construct"<<endl;
	}
	~MyClass()
	{
		cout<<"deconstruct"<<endl;
	}
	
};

int main(int argc, char const *argv[])
{
	MyClass *p = new MyClass[3];
	delete []p;
	return 0;
}