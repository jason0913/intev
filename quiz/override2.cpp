/*
override the base
*/
#include <iostream>

using namespace std;

class A
{
public:
	A(int data=0)
	{
		m_data =data;
		cout<<"call A:"<<data;
	};
	int GetData() 
	{
		return DoGetData();
	}
	virtual int DoGetData()
	{
		return m_data;
	}
	~A()
	{};
protected:
	int m_data;
};
class B:public A
{
public:
	B(int data=1)
	{
		m_data = data;
		cout<<"call B:"<<data;
	};
	int DoGetData()
	{
		return m_data;
	}
	~B(){};
protected:
	int m_data;
};

class C:public B
{
public:
	C(int data=2)
	{
		m_data =data;
		cout<<"call C,"<<data;
	}
	~C(){};
protected:
	int m_data;
};

int main(int argc, char const *argv[])
{
	C c(10);
	/*cout<<"\n-----"<<endl;
	cout<<c.m_data<<endl;
	cout<<c.B::m_data<<endl;
	cout<<c.A::m_data<<endl;*/
	cout<<"\n--------"<<endl;
	cout<<c.GetData()<<endl;
	cout<<c.A::GetData()<<endl;
	cout<<c.B::GetData()<<endl;
	cout<<c.C::GetData()<<endl;

	cout<<c.DoGetData()<<endl;
	cout<<c.A::DoGetData()<<endl;
	cout<<c.B::DoGetData()<<endl;
	cout<<c.C::DoGetData()<<endl;
	return 0;
}