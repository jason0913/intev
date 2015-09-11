/* 
* @Author: jql
* @Date:   2015-08-15 11:06:57
* @Last Modified by:   jql
* @Last Modified time: 2015-08-15 11:08:14
*/

#include <stdio.h>
#include <unistd.h>

int main() {

	int i;
	for (int i = 0; i < 4; ++i)
	{
		fork();
		printf("# ");
	}
    return 0;
}