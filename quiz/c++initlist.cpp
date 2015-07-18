/* 
* @Author: root
* @Date:   2015-07-09 21:47:28
* @Last Modified by:   root
* @Last Modified time: 2015-07-09 21:53:44
 when did initialize list to be used,1 const member 2 reference men=mber 3 child class
*/

#include <iostream>

using namespace std;

class A
{
public:
	A(int i):a(i)
	{
		// a =i;
	}
	~A(){};
private:
	int &a;
	// const int a;
};
int main(){

	A a1(1);
    return 0;
}