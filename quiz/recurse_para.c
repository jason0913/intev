/* 
* @Author: jql
* @Date:   2015-09-07 04:06:51
* @Last Modified by:   jql
* @Last Modified time: 2015-09-07 04:10:22
*/

#include <stdio.h>

void fn(int n,int *num)
{
	if (1 == n)
	{
		return ;
	}
	else
	{
		*num += 1;
		fn(n-1,num);
	}
}
int main() {

	int n =4;
	int num =0;
	fn(n,&num);
	printf("%d\n", num);
    return 0;
}