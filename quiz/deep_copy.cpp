/* 
* @Author: root
* @Date:   2015-07-26 11:23:38
* @Last Modified by:   root
* @Last Modified time: 2015-07-26 11:26:53
*/

#include <iostream>

using namespace std;

class Rect
{
public:
	Rect()
	{
		p = new int(100);
	}
	Rect(const Rect &rc)
	{
		width = rc.width;
		hight = rc.hight;
		p = new int ;
		*p = *(rc.p);
	}
	~Rect()
	{
		if (NULL != p)
		{
			delete p;
		}
	}
private:
	int width;
	int hight;
	int p;
};
int main(){

    return 0;
}