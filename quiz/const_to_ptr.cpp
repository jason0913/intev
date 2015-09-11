/* 
* @Author: jql
* @Date:   2015-08-15 04:16:07
* @Last Modified by:   jql
* @Last Modified time: 2015-08-15 04:34:04
*/

#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

	const int i =0;
	int *j = (int *)&i;
	// i = 9;
	*j = 2;
	printf("&i =%ld j =%ld \n", (long)&i,(long)j);
	printf("i =%d *j=%d\n", i,*j);
	// cout<<i <<" "<<j<<endl;
    return 0;
}