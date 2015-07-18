#include <iostream>

using namespace std;

class const_func
{
public:
	const_func(){};
	~const_func(){};
	const_func(int i):m_count(i){}
	int incr()const
	{
		return ++m_count;
	} 
	int decr()const
	{
		return --m_count;
	}
private:
	// if const func operate var ,it must mutable
 	mutable int m_count;
};

int main(int argc, char const *argv[])
{
	const_func c1(1);
	int tmp = c1.incr();
	cout<<tmp<<endl;
	return 0;
}