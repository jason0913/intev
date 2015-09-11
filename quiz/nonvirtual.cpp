/* 
* @Author: jql
* @Date:   2015-07-30 23:37:15
* @Last Modified by:   jql
* @Last Modified time: 2015-08-30 04:12:18
*/

#include <iostream>

using namespace std;

class B
{
public:
	// result diff when func become virtual
	// virtual void func()
	void func()
	{
		cout << "B func"<<endl;
	}
};
class D:public B
{
public:
	void func()
	{
		cout << "D func"<<endl;
	}
};
int main(){

	D d;
	B *pb = &d;
	D *pd = &d;
	pb->func();
	pd->func();
    return 0;
}