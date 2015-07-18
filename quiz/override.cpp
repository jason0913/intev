/*
override the virtual func in father and polymorphism
*/
#include <iostream>

using namespace std;

class A
{
public:
	
	virtual void show()
	{
		cout<<"I am A"<<endl;
	}
};

class B:public A
{
public:
	void show()
	{
		cout<<"I am B"<<endl;
	}
};
class C:public A
{
public:
	void show()
	{
		cout<<"I am C"<<endl;
	}
};

int main(int argc, char const *argv[])
{
	A *pa;
	B b;
	C c;
	pa = &b;
	pa->show();
	pa = &c;
	pa->show();
	return 0;
}