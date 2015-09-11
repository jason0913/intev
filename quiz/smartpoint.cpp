/* 
* @Author: jql
* @Date:   2015-08-11 03:36:02
* @Last Modified by:   jql
* @Last Modified time: 2015-08-11 03:42:47
*/

#include <iostream>

using namespace std;

template <class T>
class smartpoint
{
public:
	smartpoint(T *p):ptr(p)
	{

	}
	~smartpoint()
	{
		delete ptr;
	}
	T & operator *()
	{
		return *ptr;
	}
	T * operator ->()
	{
		return ptr;
	}
private:
	T *ptr;
};
class Uptr
{
public:
	friend class HasPtr;
	int *ip;
	size_t use;
	Uptr(int *p):ip(p),use(1)
	{
		cout<< "Uptr constructor call"<<endl;
	}
	~Uptr()
	{
		delete ip;
		cout <<"Uptr deconstructor call"<<endl;
	}
};
int main(){

    return 0;
}