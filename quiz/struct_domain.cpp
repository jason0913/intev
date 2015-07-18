/* 
* @Author: root
* @Date:   2015-07-13 04:16:43
* @Last Modified by:   root
* @Last Modified time: 2015-07-13 05:27:03
*/

#include <iostream>
#include <stdio.h>

using namespace std;

union V
{
	struct X
	{
		unsigned char s1:2;
		unsigned char s2:3;
		unsigned char s3:3;
	}x;
	unsigned char c;
}v;
int main(){

	v.c = 100;
	printf("%d\n", v.x.s3);
	printf("%d\n", v.x.s2);
	printf("%d\n", v.x.s1);
	cout<<"sizeof(x):"<<sizeof(v.x)<<endl;
	cout<<v.x.s3<<endl;
    return 0;
}