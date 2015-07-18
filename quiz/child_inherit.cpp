/* 
* @Author: root
* @Date:   2015-07-03 02:59:46
* @Last Modified by:   root
* @Last Modified time: 2015-07-03 04:17:36
*/

#include <iostream>

using namespace std;
class A
{
private:
	int age;
	int ShowAge()
	{
		cout<<"age:"<<age<<endl;  // private ->private
		func2();  // private ->public
	}
public:
	int func()
	{
		cout<<ShowAge();
		cout<<"call public func"<<endl;
	}
	int func2()
	{
		cout<<"private call public"<<endl;
	}
protected:
	int sex;
};
class B:private A
{
public:

	int Getage()
	{
		// return age; //can not access
	}
	int GetSex()
	{
		cout<<"return sex:";
		return sex; //can access ?
	}
};
int main(){

	B b1;
	cout<< b1.GetSex()<<endl;
	// b1.func2();
	cout<<"------"<<endl;
	A a1;
	a1.func();
    return 0;
}