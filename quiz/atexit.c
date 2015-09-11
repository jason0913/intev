/* 
* @Author: jql
* @Date:   2015-07-28 23:34:54
* @Last Modified by:   jql
* @Last Modified time: 2015-07-28 23:38:32
  main exit ,then axexit func call
*/

#include <stdio.h>
#include <stdlib.h>
int atexit(void (*function)(void));

void func1()
{
	printf("first func1\n");
}
void func2()
{
	printf("second func2\n");
}
int main() {

	atexit(func1);
	atexit(func2);
	printf("main exec\n");
    return 0;
}