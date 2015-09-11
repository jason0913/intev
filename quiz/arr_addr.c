/* 
* @Author: jql
* @Date:   2015-07-29 07:10:32
* @Last Modified by:   jql
* @Last Modified time: 2015-07-29 07:16:06
*/

#include <stdio.h>

int main() {

	int c[3][3]={1,2,3,4,5,6,7,8,9};
	int i,j;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			printf("%ld\n", &c[j]);
		}
	}
	printf("----------\n");
	printf("%ld\n", c);
	printf("%ld\n", c+1);
	printf("%ld\n", (*c+1));
	printf("%ld\n", &c[0][0]);
	printf("%ld\n", **c);
	printf("%ld\n", *c[0]);
	printf("%ld\n", *c);
    return 0;
}