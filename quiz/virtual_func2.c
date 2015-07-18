#include <iostream>
#include <stdio.h>
using namespace std;

class A
{
public:
	A(){};
	~A(){};
	virtual void print()
	{
		cout<<"this is A"<<endl;
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
		cout <<"this is B"<<endl;
	}
};

int main(int argc, char const *argv[])
{
	A a;
	B b;
	A *p1 = &a;
	A *p2 = &b;
	B *p3 = &b;
	a.print();
	b.print();
	cout <<"-----"<<endl;
	p1->print();
	p2->print();
	p3->print();
	return 0;
}