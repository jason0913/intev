#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		a=1;
	};
	~A(){};
	void print()
	{
		cout<<a<<endl;
	}

	int a;
};
class B :public A
{
public:
	B()
	{
		a=2;
	};
	~B(){};
	int a;
};
int main(int argc, char const *argv[])
{
	B b;
	b.print();
	cout<<b.a<<endl;
	return 0;
}