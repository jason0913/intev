/* 
* @Author: jql
* @Date:   2015-07-28 22:04:31
* @Last Modified by:   jql
* @Last Modified time: 2015-07-28 22:29:32
*/

#include <iostream>

using namespace std;

int main(){

	int a = 248;
	int b = 4;
	int const c =2;
	const int *d = &a;
	int * const e =&b;
	int const * const f = &a;
	*c = 32;
	*d =43;
	a =100;
	b =34;
	e =&a;
	f = 0x321f;
    return 0;
}