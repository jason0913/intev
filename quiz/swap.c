/* 
* @Author: jql
* @Date:   2015-08-22 04:01:59
* @Last Modified by:   jql
* @Last Modified time: 2015-08-22 04:04:12
*/

#include <stdio.h>

void foo(int *a,int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
int main() {

	int a=1,b=2,c=3;
	foo(&a,&b);
	foo(&b,&c);
	foo(&c,&a);
	printf("%d %d %d\n", a,b,c);
    return 0;
}