/* 
* @Author: jql
* @Date:   2015-08-16 21:16:29
* @Last Modified by:   jql
* @Last Modified time: 2015-08-16 21:18:34
*/

#include <stdio.h>

int main() {

	struct A
	{
		char a;
		char b;
		char c;
	};
	struct B
	{
		int a;
		char b;
		short c;
	};
	struct C
	{
		char b;
		int a;
		short c;
	};
	printf("sizeof(A):%d\n", sizeof(A));
	printf("sizeof(B):%d\n", sizeof(B));
	printf("sizeof(C):%d\n", sizeof(C));
    return 0;
}