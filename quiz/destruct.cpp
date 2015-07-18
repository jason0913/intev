#include <iostream>
#include <string>

using namespace std;

class B
{
public:
	B()
	{
		cout<<"defalut construct"<<endl;
	}
	~B()
	{
		cout<<"destructed"<<endl;
	}
	B(int i):data(i)
	{
		cout<<"construct by param "<<i<<endl;
	}
private:
	int data;
};

B play(B b)
{
	return b;
}

int main(int argc, char const *argv[])
{
	B tmp = play(5);
	return 0;
}