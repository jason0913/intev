#include <iostream>

using namespace std;

class BASE
{
public:
	// ~BASE() drived class can not inhert this if dont have virtual
	virtual ~BASE()
	{
		cout<<"Base deconstruction"<<endl;
	}
	
};
class CCHILD: public BASE
{
public:
	~CCHILD()
	{
		cout<<"CCHILD deconstruction"<<endl;
	}
	
};

int main(int argc, char const *argv[])
{
	BASE *Pbase;
	BASE *b = new BASE;
	CCHILD *c = new CCHILD;
	/*BASE b;
	CCHILD c;*/
	// Pbase = &b;
	Pbase = b;
	delete Pbase;
	cout<<"-----"<<endl;
	// Pbase = &c;
	Pbase = c;
	delete Pbase;
	return 0;
}