/* 
* @Author: jql
* @Date:   2015-08-15 10:46:56
* @Last Modified by:   jql
* @Last Modified time: 2015-08-15 10:48:31
*/

#include <stdio.h>

#define f(x) x*x

int main() {

	int a =6,b =2,c;
	c = f(a)/f(b);
	printf("%d\n", c);
    return 0;
}