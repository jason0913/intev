#include <iostream>

using namespace std;

struct AbsInt
{
	int operator()(int val)
	{
		return val >0 ? val:-val;
	}
};

int main(int argc, char const *argv[])
{
	int i = -10;
	AbsInt obj;
	cout<< obj(i)<<endl;
	return 0;
}