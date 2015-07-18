/* 
* @Author: root
* @Date:   2015-07-13 06:10:41
* @Last Modified by:   root
* @Last Modified time: 2015-07-16 22:13:20
*/

#include <iostream>

using namespace std;

class A
{
public:
	A()
	{
		cout<<"call constructor"<<endl;
		i =0;
	}
	A (const A &a)
	{
		cout<<"copy constructor"<<endl;
		i = a.i;
	}
private:
	int i;
};
int main(){

	A a1;
	cout<<"-----"<<endl;
	A a2 = a1;
    return 0;
}