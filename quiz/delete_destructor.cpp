/* 
* @Author: root
* @Date:   2015-07-13 05:57:57
* @Last Modified by:   root
* @Last Modified time: 2015-07-13 06:31:48
*/

#include <iostream>

using namespace std;

class A
{
public:
	A()
	{
		i =10;
	}
	~A()
	{
		cout<<"call destructor"<<endl;
	}
private:
	int i;
};
int main(){

	A a;
	A *p = &a;
	delete p;
    return 0;
}