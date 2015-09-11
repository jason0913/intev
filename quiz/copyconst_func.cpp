/* 
* @Author: jql
* @Date:   2015-08-15 11:15:32
* @Last Modified by:   jql
* @Last Modified time: 2015-08-17 22:42:48
*/

#include <iostream>

using namespace std;

class A
{
public:
	A(){cout<<"constuction call"<<endl;}
	A(int a){cout<<"constuction call with para"<<endl;;}
	A(int &a){cout<<"A call"<<endl;}
	A & operator=(A &a)
	{
		cout<<"operator func call"<<endl;
		A b;
		b = a;
		return b;
	}
};

A f(A u)
{
	A v(u);
	A w = v;
	return w;
}
int main(){

	A x;
	A y = f(f(x));
    return 0;
}