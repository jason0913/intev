#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class A
{
public:
	A(){};
	~A(){};
	virtual void print()
	{
		cout<<"this is A 1"<<endl;
	}
	virtual void print2()
	{
		cout<<"this is A 2"<<endl;
	}
};
//the func in child class become virtual automaticlly
class B:public A
{
public:
	B(){};
	~B(){};
	void print()
	{
		cout <<"this is B3"<<endl;
	}
	virtual void print2()
	{
		cout<<"this is B4"<<endl;
	}
};

int main(int argc, char const *argv[])
{
	A a;
	B b;
	void (*func)(A *);
	A *p = new B;
	long lvptraddr = NULL;

	A *p1 = &a;
	A *p2 = &b;
	B *p3 = &b;
	cout <<"-----"<<endl;
	p1->print();
	p2->print();
	p3->print();

	memcpy(&lvptraddr,p,4);
	memcpy(&func,reinterpret_cast<long *>(lvptraddr),4);
	cout<<"-----"<<endl;
	func(p);
	return 0;
}