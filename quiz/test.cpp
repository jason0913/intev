#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class A
{
public:
    A(int a=0):data(a)
    {}
    int getData()
    {
        return doGetData();
    }
    virtual int doGetData()
    {
        return data;
    }
private:
    int data;

};

class B : public  A
{
public:
    B(int a=1):data(a)
    {
    }
    int doGetData()
    {
        return data;
    }
private:
    int data;
};

class C:public B
{
public:
    C(int a=2):data(a)
    {}
private:
    int data;
};


int main()
{
    C c(10);
    cout<<c.A::doGetData()<<endl;
    cout<<c.B::doGetData()<<endl;
    cout<<c.doGetData()<<endl;
    cout<<c.getData()<<endl;
    cout<<c.A::getData()<<endl;
    cout<<c.B::getData()<<endl;
    cout<<c.C::getData()<<endl;


}
