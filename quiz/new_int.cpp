/* 
* @Author: jql
* @Date:   2015-08-22 07:11:54
* @Last Modified by:   jql
* @Last Modified time: 2015-08-22 07:15:03
  the diff between new
*/

#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

	int * p1 = new int[10];
	int * p2 = new int[10]();

	int i;
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", *(p1+i));
	}
	printf("-------\n");
	
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", *(p2+i));
	}
    return 0;
}