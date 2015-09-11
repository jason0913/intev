/* 
* @Author: jql
* @Date:   2015-08-31 09:20:46
* @Last Modified by:   jql
* @Last Modified time: 2015-08-31 09:24:21
*/

#include <iostream>

using namespace std;

class A
{
public:
	long a;
};
class B: public A
{
public:
	long b;
};

void seta(A *data,int index)
{
	data[index].a =2;
}
int main(){

	B data[4];
	for (int i = 0; i < 4; ++i)
	{
		data[i].a =1;
		data[i].b =1;
		seta(data,i);
	}
	for (int i = 0; i < 4; ++i)
	{
		cout<<data[i].a<<" "<<data[i].b<<endl;
	}
    return 0;
}