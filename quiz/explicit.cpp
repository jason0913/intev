#include <iostream>

using namespace std;

class gxgexplicit
{
public:
    explicit gxgexplicit(int n)
	{
		size = n;
	}
	int get()
	{
		return size;
	}
private:
	int size;
};

int main(int argc, char const *argv[])
{
	gxgexplicit ge1(24);
	gxgexplicit ge2 =1;
	// gxgexplicit ge3;

	ge1 = 1;
	ge2 = 2;
	// ge3 = 3;
	cout<<"ge1 "<<ge1.get()<<endl;
	cout<<"ge2 "<<ge2.get()<<endl;
	return 0;
}