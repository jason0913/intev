/* 
* @Author: root
* @Date:   2015-07-20 23:12:37
* @Last Modified by:   root
* @Last Modified time: 2015-07-20 23:25:19
 the para of copy constructor
*/

#include <iostream>

using namespace std;
class EXample
{
private:
	int m_ntest;
public:
	EXample(int x):m_ntest(x)
	{
		cout<<"constructor with para"<<endl;
	}
	EXample(const EXample &ex)
	{
		m_ntest = ex.m_ntest;
		cout<<"copy constructor"<<endl;
	}
	EXample & operator=(const EXample &ex)
	{
		if (*this == ex)
		{
			cout<<"assign self"<<endl;
			return *this;
		}
		m_ntest = ex.m_ntest;
		cout<<"assign constructor"<<endl;
		return *this;
	}
	bool operator==(const EXample &ex)
	{
		return (ex.m_ntest == this->m_ntest);
	}
	~EXample(){};
	void Myfunc(EXample ex)
	{

	}
};
int main(){

	EXample aaa(2);
	EXample bbb(3);
	bbb = aaa;
	bbb = bbb;
	EXample ccc =aaa;
	bbb.Myfunc(aaa);
    return 0;
}