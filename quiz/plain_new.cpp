/* 
* @Author: root
* @Date:   2015-06-29 22:49:24
* @Last Modified by:   root
* @Last Modified time: 2015-06-29 22:54:49
*/

#include <iostream>

using namespace std;

char *GetMem(unsigned long size)
{
	char *p = new char[size];
	return p;
}
int main(){

	try
	{
		char *p = GetMem(10e11);
		if (!p)
		{
			cout<<"GetMem failed"<<endl;
			delete []p;
		}
	}
	catch(std::bad_alloc &ex)
	{
		cout<<ex.what()<<" failed no NULL"<<endl;
	}
    return 0;
}