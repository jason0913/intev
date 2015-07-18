/* 
* @Author: root
* @Date:   2015-06-30 09:02:56
* @Last Modified by:   root
* @Last Modified time: 2015-06-30 09:13:05
*/

#include <iostream>

using namespace std;
class A
{
	char k[3];
public:
	virtual void aa(){}
};
class B:public virtual A
{
	char j[3];
public:
	virtual void bb(){}
};
class C:public virtual B
{
	char i[3];
public:
	virtual void cc(){}
};
int main(){

	cout<<"sizeof(A)"<<sizeof(A)<<endl;
	cout<<"sizeof(B)"<<sizeof(B)<<endl;
	cout<<"sizeof(C)"<<sizeof(C)<<endl;
    return 0;
}