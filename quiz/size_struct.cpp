/* 
* @Author: root
* @Date:   2015-07-01 03:07:21
* @Last Modified by:   root
* @Last Modified time: 2015-07-01 03:11:43
*/

#include <iostream>
#include <stdio.h>

using namespace std;

struct a
{
	int x:1;
	int y:2;
	int z:33;
};
int main(){

	a d;
	cout<<&d<<endl;
	d.z = d.x+d.y;
	printf("%d %d %d %d\n", d.x,d.y,d.z,sizeof(d));
    return 0;
}