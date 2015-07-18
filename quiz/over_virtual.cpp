#include <iostream>

using namespace std;

class A
{
public:
	void virtual f()
	{
		cout<<"A "<<endl;
	}
};
class B:public A
{
public:
	void virtual f()
	{
		cout<<"B "<<endl;
	}
};

int main(int argc, char const *argv[])
{
	A *pa = new A();
	pa->f();

	B *pb = (B*)pa;
	pb->f();
	pa->f();
	
	delete pa,pb;
	pa = new B();
	pa->f();
	pb =(B*)pa;
	pb->f();
	return 0;
}