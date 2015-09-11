/* 
* @Author: jql
* @Date:   2015-08-22 04:22:31
* @Last Modified by:   jql
* @Last Modified time: 2015-08-22 04:29:23
*/

#include <iostream>
#include <stdio.h>

using namespace std;

class Base
{
public:
	int Bar(char x)
	{
		return (int)x;
	}
	virtual int Bar(int x)
	{
		return 2*x;
	}
};
class Derived:public Base
{
public:
	int Bar(char x)
	{
		return (int)(-x);
	}
	int Bar(int x)
	{
		return x/2;
	}
};
int main(){

	Derived obj;
	Base *pb = &obj;
	printf("%d\n", pb->Bar((char)(100)));
	printf("%d\n", pb->Bar(100));
    return 0;
}