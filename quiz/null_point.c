/* 
* @Author: root
* @Date:   2015-07-01 04:12:47
* @Last Modified by:   root
* @Last Modified time: 2015-07-01 07:50:40
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char *ptr;
	if ((ptr = (char*)malloc(0)) ==NULL)
	{
		printf("Got a NULL point\n");
	}
	else
		printf("Got a invalid point\n");
	
	printf("%d\n", sizeof((char*)malloc(0)));
	printf("%d\n", sizeof(NULL));
	int res = strlen((char*)malloc(0));
	printf("%d\n", res);
    return 0;
}