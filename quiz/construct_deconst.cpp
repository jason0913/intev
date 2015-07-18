#include <iostream>

using namespace std;

class C
{
public:
	C()
	{
		cout<<"consruct C"<<endl;
	};
	~C()
	{
		cout<<"deconstruct C"<<endl;
	};
	
};
class B
{
public:
	B()
	{
		cout<<"consruct B"<<endl;
	};
	~B()
	{
		cout<<"deconstruct B"<<endl;
	};
protected:
	C c1;
};

class A :public B
{
public:
	A()
	{
		cout<<"consruct A"<<endl;
	};
	~A()
	{
		cout<<"deconstruct A"<<endl;
	};
protected:
	C c2;
};

int main(int argc, char const *argv[])
{
	A a1;
	return 0;
}