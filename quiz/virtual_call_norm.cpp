/* 
* @Author: jql
* @Date:   2015-08-21 23:40:21
* @Last Modified by:   jql
* @Last Modified time: 2015-08-22 06:55:47
*/

#include <iostream>

using namespace std;

class Base
{
public:
	Base(int j):i(j){};
	virtual ~Base(){};

	void func1()
	{
		cout<<"in Base func1,then call func2"<<endl;
		i *= 10;
		func2();
	}
	int GetValue()
	{
		return i;
	}
protected:
	virtual void func2()
	{
		cout<<"in Base func2"<<endl;
		i++;
	}
	int i;
};
class Child:public Base
{
public:
	Child(int j):Base(j){};
	~Child(){};
	void func1()
	{
		cout<<"in Child func1,then call func2"<<endl;
		i *= 100;
		func2();
	}
	void func2()
	{
		cout<<"in Child func2"<<endl;
		i +=2;
	}
	
};
int main(){

	Base *pb = new Child(1);
	pb->func1();
	cout<<"GetValue "<<pb->GetValue()<<endl;
	delete pb;
	cout <<"sizeof(double)"<<sizeof(double)<<endl;
    return 0;
}