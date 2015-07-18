#include <iostream>
#include <complex>

/*
sizeof null class and has a virtual func
*/
using namespace std;

class base
{
public:
	base(){};
	~base(){};
	virtual void f(int)
	{
		cout<<"base f(int)"<<endl;
	}
	virtual void f(double)
	{
		cout<<"base:: f(double"<<endl;
	}
	virtual void g(int i=10)
	{
		cout<<"base::g()"<<endl;
	}
	virtual void g2(int i=10)
	{
		cout<<"base::g2()"<<endl;
	}
};
class derived
{
public:
	derived(){};
	~derived(){};
	void f(complex<double>)
	{
		cout<<"derived::f(complex)"<<endl;
	}
	virtual void g(int i=20)
	{
		cout<<"derived::g()"<<endl;
	}
};
class null1
{
public:
	null1(){};
	~null1(){};
	void f(){};
public:
	// double a;
};
class null2
{
public:
	null2(){};
	~null2(){};
	virtual void f(){};
};
class null3:public null1
{
public:
	null3(){};
	~null3(){};
	
};
class null4:public virtual null1
{
public:
	null4(){};
	~null4(){};
	
};
int main(int argc, char const *argv[])
{
	base b;
	derived d;
	// base *pb = new derived;
	cout<<"sizeof(base)"<<sizeof(base)<<"\t";
	cout<<"sizeof(derived)"<<sizeof(derived)<<endl;
	cout<<"sizeof(null1 class)"<<sizeof(null1)<<endl;
	cout<<"sizeof(null2 class has virtual func)"<<sizeof(null2)<<endl;
	cout<<"sizeof(null3 :public null1)"<<sizeof(null3)<<endl;
	cout<<"sizeof(null4 :public virtual null1)"<<sizeof(null4)<<endl;
	return 0;
}