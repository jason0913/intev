/* 
* @Author: jql
* @Date:   2015-07-30 23:18:15
* @Last Modified by:   jql
* @Last Modified time: 2015-07-30 23:33:35
*/

#include <iostream>

using namespace std;

class BASE
{
public:
	virtual void f1()=0;
	virtual void f1(int)
	{
		cout<<"BASE f1 para int"<<endl;
	}
	virtual void f2()
	{
		cout <<"BASE f2"<<endl;
	}
	void f3()
	{
		cout<<"BASE f3"<<endl;
	}
	void f3(double)
	{
		cout<<"BASE f3 para double"<<endl;
	}

};
class Derived:public BASE
{
public:
	virtual void f1()
	{
		cout<<"Derived f1"<<endl;
	}
	void f3()
	{
		cout<<"Derived f3"<<endl;
	}
	void f4()
	{
		cout<<"Derived f4"<<endl;
	}
};
int main(){

	Derived d;
	int x;;
	double y;
	d.f1();
	// d.f1(x);
	d.BASE::f1(x);
	d.f2();
	d.f3();
	// d.f3(y);
	d.BASE::f3(y);
    return 0;
}