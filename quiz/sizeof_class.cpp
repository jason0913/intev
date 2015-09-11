/* 
* @Author: jql
* @Date:   2015-08-21 23:28:02
* @Last Modified by:   jql
* @Last Modified time: 2015-08-22 03:49:04
*/

#include <iostream>

using namespace std;
class A
{
public:
	int a;
	short b;
	int c;
	char d;
};
class B
{
public:
	double a;
	short b;
	int c;
	char d;
};
int main(){

	cout<<"sizeof(A) "<<sizeof(A)<<endl;
	cout<<"sizeof(B) "<<sizeof(B)<<endl;
    return 0;
}