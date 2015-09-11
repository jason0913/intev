/* 
* @Author: jql
* @Date:   2015-07-27 02:57:42
* @Last Modified by:   jql
* @Last Modified time: 2015-07-27 03:02:19
*/

#include <iostream>

using namespace std;

template <typename T>
T Add(T a,T b)
{
	T result = a+b;
	return result;
}
int main(){

	cout<<"2+3:"<<Add(2,3)<<endl;
	cout<<"1.2+3.2:"<<Add(1.2,3.2)<<endl;
	cout<<"abc +edf:"<<Add(string("adc"),string("efg"));
    return 0;
}