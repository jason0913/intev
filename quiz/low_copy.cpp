/* 
* @Author: root
* @Date:   2015-07-26 11:15:12
* @Last Modified by:   root
* @Last Modified time: 2015-07-26 11:20:15
*/

#include <iostream>

using namespace std;

class Test
{
public:
	Test(int tmp):p1(tmp)
	{
		cout<<"construtot with para"<<endl;
	};
	Test(const Test &tc)
	{
		cout<<"copy construtot"<<endl;
		p1 = tc.p1;
	}
	~Test()
	{
		cout<<"deconstrctor"<<endl;
	}
	int p1;
};
int main(){

	Test a(99);
	Test b =a;
	cout<<b.p1<<endl;
    return 0;
}