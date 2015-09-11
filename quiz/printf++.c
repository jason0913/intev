/* 
* @Author: jql
* @Date:   2015-08-16 08:57:51
* @Last Modified by:   jql
* @Last Modified time: 2015-08-16 08:59:23
*/

#include <stdio.h>

void print_value(int *x)
{
	// printf("%d\n", ++*x);
	printf("%x\n", ++*x);
}
int main() {

	int a =25;
	print_value(&a);
    return 0;
}