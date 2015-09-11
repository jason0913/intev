/* 
* @Author: jql
* @Date:   2015-08-06 07:18:06
* @Last Modified by:   jql
* @Last Modified time: 2015-08-06 07:39:42
 count the num of sub set
*/

#include <stdio.h>

int subsetnum(int size)
{
	if (size <0)
	{
		return -1;
	}
	if (0 == size)
	{
		size = 1;
	}
	else if (1 == size)
	{
		size = 2;
	}
	else
		size = subsetnum(size-1) + subsetnum(size-1);
	return size;
}
int main() {

	int setsize;
	printf("Input set size:\n");
	scanf("%d",&setsize);
	printf("subsetnum: %d\n", subsetnum(setsize));
    return 0;
}