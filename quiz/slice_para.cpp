/* 
* @Author: jql
* @Date:   2015-09-03 04:48:07
* @Last Modified by:   jql
* @Last Modified time: 2015-09-03 04:53:22
*/

#include <iostream>

using namespace std;

class Base
{
public:
	virtual void show() const
	{
		cout<<"Base show"<<endl;
	}
};
class Deried:public Base
{
public:
	virtual void show() const
	{
		cout<<"Deried show"<<endl;
	}
};
// void print_show(Base b) //Base show, object slice
void print_show(Base &b)
{
	b.show();
}
int main(){

	Deried d;
	print_show(d);
    return 0;
}