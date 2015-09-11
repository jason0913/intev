/* 
* @Author: jql
* @Date:   2015-08-16 04:27:04
* @Last Modified by:   jql
* @Last Modified time: 2015-08-16 04:28:03
*/

#include <stdio.h>

int main() {

	unsigned int a = 0x1234;
	unsigned char b = *(unsigned char*)&a;
	printf("%c\n", b);
    return 0;
}