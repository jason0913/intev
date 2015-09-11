/* 
* @Author: jql
* @Date:   2015-07-31 11:36:50
* @Last Modified by:   jql
* @Last Modified time: 2015-08-03 07:47:10
*/

#include <iostream>

using namespace std;

class B
{
public:
	// virtual ~B()
	~B()
	{
		cout<<"B deconstructor"<<endl;
	}
	
};
class D: public B
{
public:
	~D()
	{
		cout<<"D deconstructor"<<endl;
	}
	
};
int main(){

	B *pb = new D;
	delete pb;
    return 0;
}