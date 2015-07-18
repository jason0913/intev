/* 
* @Author: root
* @Date:   2015-06-30 09:31:22
* @Last Modified by:   root
* @Last Modified time: 2015-06-30 09:33:46
*/

#include <iostream>

using namespace std;

class A
{
public:
	A(){};
	~A(){};
	void foo()
	{
		cout<<"foo A"<<endl;
	}
};
class B
{
public:
	B(){};
	~B(){};
	void foo()
	{
		cout<<"foo B"<<endl;
	}
};
class C:public A,public B
{
public:
	C(){};
	~C(){};
	
};
int main(){
	C c1;
	c1.A::foo();
	c1.B::foo();
    return 0;
}