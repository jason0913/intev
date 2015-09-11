/* 
* @Author: jql
* @Date:   2015-08-15 10:38:09
* @Last Modified by:   jql
* @Last Modified time: 2015-08-15 10:40:06
*/

#include <stdio.h>

int main() {

	int i;
	for (int i = 0; i < 3; ++i)
	{
		switch(i)
		{
			case 0:
			 	printf("%d", i);
			case 2:
				printf("%d", i);
			default:

				printf("%d", i);
		}
	}
    return 0;
}