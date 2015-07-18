/* 
* @Author: root
* @Date:   2015-07-13 04:24:56
* @Last Modified by:   root
* @Last Modified time: 2015-07-13 06:39:12
*/

#include <iostream>
#include <stdio.h>

using namespace std;

class A
{
public:
	A()
	{
		cout<<"call constructor"<<endl;
		p = this;
	};
	~A()
	{
		cout<<"clall destructor"<<endl;
		if (NULL != p)
		{
			// delete p;
			p = NULL;
		}
	}
	A *p;
};
int main(){

	A a;
	printf("%x\n", &a);
	printf("%x\n", a.p);
    return 0;
}