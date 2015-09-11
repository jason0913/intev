/* 
* @Author: jql
* @Date:   2015-08-03 03:26:53
* @Last Modified by:   jql
* @Last Modified time: 2015-08-03 03:30:15
*/

#include <stdio.h>
#include <libgen.h>

int main(int argc,char * argv[]) {

	if (2 != argc)
	{
		printf("Usage: %s ipaddr\n", basename(argv[0]));
	}
    return 0;
}