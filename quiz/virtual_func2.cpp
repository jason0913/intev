/* 
* @Author: root
* @Date:   2015-07-13 05:03:14
* @Last Modified by:   root
* @Last Modified time: 2015-07-16 11:10:27
*/

#include <iostream>

using namespace std;

class A
{
public:
	virtual void print()
	{
		cout<<"A:print"<<endl;
	}
protected:
	int data;
};
class B:public A
{
public:
	virtual void print()
	{
		cout<<"B:print"<<endl;
	}
};

class C:public B
{
public:
	virtual void print()
	{
		cout<<"C:print"<<endl;
	}
};
void print(A a)
{
	a.print();
}
int main(){

	A a,*pa,*pb,*pc;
	B b;
	C c;

	pa = &a;
	pb = &b;
	pc = &c;

	a.print();
	b.print();
	c.print();

	pa->print();
	pb->print();
	pc->print();

	print(a);
	print(b);
	print(c);
    return 0;
}