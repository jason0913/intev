/* 
* @Author: jql
* @Date:   2015-08-23 04:39:10
* @Last Modified by:   jql
* @Last Modified time: 2015-08-23 04:42:48
*/

#include <stdio.h>

int IncArray(int array[],int len)
{
	if (1 == len)
	{
		return true;
	}
	if (2 == len)
	{
		return array[len-1] >array[len -2];
	}
	return IncArray(array,len -1) && (array[len -1] > array[len -2]);
}
int main() {

	int array[] ={1,2,3,4,9,5};
	int len = sizeof(array) /sizeof(array[0]);
	int res;
	res = IncArray(array,len);
	printf("%d\n", res);
    return 0;
}