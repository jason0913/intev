/* 
* @Author: jql
* @Date:   2015-07-28 21:11:27
* @Last Modified by:   jql
* @Last Modified time: 2015-07-28 21:21:12
*/

#include <stdio.h>

int main() {

	int **p;
	int arr[100];
	p = &arr;
	printf("arr=%x\n", arr);
	printf("&arr=%x\n", &arr);
    return 0;
}