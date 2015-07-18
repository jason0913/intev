#include <iostream>

using namespace std;

class A
{
public:
	A(){};
	A(int n){a = n;};
	~A(){};
	int Get()
	{
		return a;
	}
private:
	int a;
};

int main(int argc, char const *argv[])
{
	A b(10);
	b.a;
	cout<< b.Get()<<endl;
	return 0;
}