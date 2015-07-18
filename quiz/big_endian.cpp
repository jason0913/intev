/* 
* @Author: root
* @Date:   2015-07-13 01:02:45
* @Last Modified by:   root
* @Last Modified time: 2015-07-13 05:00:19
*/

#include <iostream>

using namespace std;

bool IsBigEdian()
{
	unsigned short u = 0x1122;
	unsigned char *c = (unsigned char*)&u;

	if (0x22 == *c)
	{
		return true;
	}
	else
		return false;
}
int main(){

	cout<<"IsBigEdian:"<<IsBigEdian()<<endl;
    return 0;
}