/* 
* @Author: jql
* @Date:   2015-08-25 03:12:40
* @Last Modified by:   jql
* @Last Modified time: 2015-08-25 03:15:16
can not alloc obj in stack
*/

#include <iostream>

using namespace std;

class A
{
public:
	A(){};
private:
	~A(){};
};

int main(){

	// A a;  // can do this because deconstruct is private
	A *pa = new A;  // ok, new in the dump
    return 0;
}