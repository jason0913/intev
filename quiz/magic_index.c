/* 
* @Author: jql
* @Date:   2015-08-06 06:54:59
* @Last Modified by:   jql
* @Last Modified time: 2015-08-06 07:03:55
  magic index: array[i] =i
*/

#include <stdio.h>

// the slow one to find magic index
int magic_index1(int array[],int start,int end)
{
	if (NULL == array || start > end)
	{
		return -1;
	}
	int i;
	for (int i = 0; i < end; ++i)
	{
		if (array[i] == i)
		{
			return i;
		}
	}
	return -1;
}
// fast find magic index by binsearch
int magic_index2(int array[],int start,int end)
{
	if (NULL == array || start > end)
	{
		return -1;
	}
	int mid = (start + end) /2;
	if (mid == array[mid])
	{
		return mid;
	}
	else if (mid > array[mid])
	{
		magic_index2(array,mid+1,end);
	}
	else
		magic_index2(array,start,mid -1);
}
int main() {

	int array[] = {-1,1,3,5,7,9};
	int len = sizeof(array) /sizeof(array[0]);
	printf("magic_index1 : %d\n", magic_index1(array,0,len));
	printf("magic_index2 : %d\n", magic_index2(array,0,len));
    return 0;
}