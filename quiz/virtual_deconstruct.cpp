#include <iostream>

using namespace std;

class BASE
{
public:
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
	CCHILD c;
	Pbase = &c;
	delete Pbase;
	return 0;
}