/* 
* @Author: jql
* @Date:   2015-08-31 22:27:43
* @Last Modified by:   jql
* @Last Modified time: 2015-08-31 22:41:52
*/

#include <iostream>

using namespace std;

class A
{
public:
	int x;
	A(int y):x(y){;}
	virtual void show()
	{
		cout<<"auto inherit:" <<x<<endl;
	}
};
class B:public A
{
public:
	int y;
	B(int z):A(z),y(z){;}

};
int main(){

	A *pa = new B(1);
	// B b;
	pa->show();
    return 0;
}