/* 
* @Author: root
* @Date:   2015-07-14 08:06:54
* @Last Modified by:   root
* @Last Modified time: 2015-07-14 08:13:52
 does default constructor will call constructor with paramters
*/

#include <iostream>

using namespace std;

class CLS
{
public:
	CLS()
	{
		CLS(2);
	}
	CLS(int i):m_i(i){};
	~CLS(){};
	
	int m_i;
};
int main(){

	CLS obj;
	cout<<obj.m_i<<endl;
    return 0;
}