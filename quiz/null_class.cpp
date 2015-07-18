/*************************************************************************
    > File Name: null_class.cpp
    > Author: liujunq2
    > Mail: liujunq2@163.com 
    > Created Time: Fri 20 Mar 2015 04:04:42 AM EDT
 ************************************************************************/

#include<iostream>
using namespace std;

class A
{

};
class B
{
	public:
	 B()
	 {

	 }
	virtual~ B()
	{

	}

};
int main(int argc, const char *argv[])
{
	int len,lenb;
	A a;
	B b;
	len = sizeof(a);
	lenb = sizeof(b);
	cout << "null class len "<< len <<endl;
	cout << "null with construct class len "<< lenb <<endl;
	return 0;
}
