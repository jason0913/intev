/* 
* @Author: jql
* @Date:   2015-08-22 03:02:55
* @Last Modified by:   jql
* @Last Modified time: 2015-08-22 06:08:37
*/

#include <iostream>

using namespace std;

class A
{
public:
	A()
	{
		cout <<"A "<<endl;
	};
	~A()
	{
		cout<<"~A deconstruct"<<endl;
	}
};

class B:public A
{
public:
	B(A &a):_a(a)
	{
		cout<<"B "<<endl;
	};
	/*B()
	{
		cout<<"B "<<endl;
	};*/
	~B()
	{
		cout<<"~B deconstruct"<<endl;
	}
private:
	A &_a;
};

int main(){

	A a;
	B b(a);
	cout<<"reference and ponit do not call constructor"<<endl;
	A &aa = a;
	A *pa = &a;
	// B b;
    return 0;
}