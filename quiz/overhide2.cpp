/* 
* @Author: jql
* @Date:   2015-08-31 09:00:00
* @Last Modified by:   jql
* @Last Modified time: 2015-08-31 09:09:32
*/

#include <iostream>

using namespace std;

class A
{
public:
	virtual void f()
	{
		cout<<"virtual void A::f()"<<endl;
	}
	void f()const
	{
		cout<<"A::const f()"<<endl;
	}
};
class B: public A
{
public:
	void f()
	{
		cout<<"B:: f()"<<endl;
	}
	void f() const
	{
		cout<<"B:: f() const"<<endl;
	}
};

void G(const A *a)
{
	a->f();
}
int main(){

	A *p = new B;
	p->f();
	G(p);
	delete p;
    return 0;
}