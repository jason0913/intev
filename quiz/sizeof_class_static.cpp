/* 
* @Author: jql
* @Date:   2015-08-31 21:18:33
* @Last Modified by:   jql
* @Last Modified time: 2015-08-31 21:24:06
*/

#include <iostream>

using namespace std;

struct A
{
	A(){};
	~A(){};
	int m1;
	int m2;
};
struct B:A
{
	B(){};
	~B(){};
	int m1;
	char m2;
	static char m3;
	static char * p1;  // static not alloc mem in obj
};
struct C
{
	C(){};
	virtual ~C(){};
	int m1;
	short m2;
};

int main(){

	cout<<"sizeof(A)"<<sizeof(A)<<endl;
	cout<<"sizeof(B)"<<sizeof(B)<<endl;
	cout<<"sizeof(C)"<<sizeof(C)<<endl;
    return 0;
}