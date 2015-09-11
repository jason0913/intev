/* 
* @Author: jql
* @Date:   2015-08-05 22:06:36
* @Last Modified by:   jql
* @Last Modified time: 2015-08-05 22:10:52
  1 ,2 or 3 step/per
*/

#include <stdio.h>

int count_step(int n)
{
	if (n < 0)
	{
		return 0;
	}
	else if (0 == n)
	{
		return 1;
	}
	else
		return count_step(n-1) + count_step(n-2) + count_step(n-3);
}
int main() {

	int i =0;
	for (int i = 0; i < 10; ++i)
	{
		printf("%d step ,count_step %d\n", i,count_step(i));
	}
    return 0;
}