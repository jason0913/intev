/* 
* @Author: jql
* @Date:   2015-09-02 11:18:53
* @Last Modified by:   jql
* @Last Modified time: 2015-09-02 11:42:25
*/

#include <iostream>
#include <memory>

using namespace std;

class A
{
public:
	A()
	{
		i =10;
		cout<<"construct A"<<endl;
	}
	~A()
	{
		cout<<"deconstruct A"<<endl;
	}
	void show()
	{
		cout<<"resource"<<endl;
	}
	int i;
};
int getv(const A *pa)
{
	pa->show();
}
int main(){

	auto_ptr<A> pa(A());
	getv(pa.get());
	// auto_ptr<A> pb(A());
	// auto_ptr<A> pb(pa);
    return 0;
}