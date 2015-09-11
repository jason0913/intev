/* 
* @Author: jql
* @Date:   2015-08-27 11:06:03
* @Last Modified by:   jql
* @Last Modified time: 2015-08-27 11:15:34
*/

#include <stdio.h>
#include <stdlib.h>
#include <mcheck.h>

int main() {

	setenv("MALLOC_TRACE", "./memtrace.log", 1);
	mtrace();
	char *p = (char*)malloc(100);
    return 0;
}