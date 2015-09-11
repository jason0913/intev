/* 
* @Author: jql
* @Date:   2015-08-09 02:06:48
* @Last Modified by:   jql
* @Last Modified time: 2015-08-09 02:23:30
 longest increment sequence
*/

#include <iostream>
#include <stdio.h>

using namespace std;

int dp[100];
int longestlen =0;

int LCS(int *array,int size)
{
	if (NULL == array || size < 0)
	{
		return 0;
	}
	for (int i = 0; i < size; ++i)
	{
		dp[i] = 1;
		for (int j = 0; j < i; ++j)
		{
			if (array[i] > array[j] && dp[i] <dp[j] +1)
			{
				dp[i] = dp[j] +1;
				if (dp[i] > longestlen)
				{
					longestlen = dp[i];
				}
			}
		}
	}
	return longestlen;
}

void PrintLCS(int *array,int index)
{
	bool IsLCS = false;
	if (NULL == array || index < 0)
	{
		return;
	}
	if (dp[index] == longestlen)
	{
		--longestlen;
		IsLCS = true;
	}
	PrintLCS(array,--index);
	if (IsLCS)
	{
		printf("%d ", array[index+1]);
	}
}
int main(){

	int array[] = {1,-1,2,-3,4,-5,6,-7};
	printf("longestlen %d\n", LCS(array,sizeof(array)/sizeof(array[0])));
	PrintLCS(array,sizeof(array)/sizeof(array[0]) -1);
    return 0;
}