#include <iostream>

using namespace std;

class 	A
{
public:
		A(int n){value = n;};
		A(const A other){value = other.value;}
		void print(){cout<<value <<endl;}
	~	A(){};
private:
	int value;
};

int main(int argc, char const *argv[])
{
	A a=10;
	A b =a;
	b.print();
	return 0;
}