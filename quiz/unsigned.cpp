/* 
* @Author: root
* @Date:   2015-07-01 03:45:26
* @Last Modified by:   root
* @Last Modified time: 2015-07-01 03:48:21
*/

#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

	unsigned short int i =0;
	int j =8,p;
	p = j <<1;
	i = i-1;
	printf("i = %d\n", i);
	printf("p = %d\n", p);
	printf("sizeof(usint): %d\n",sizeof(unsigned short int));
    return 0;
}