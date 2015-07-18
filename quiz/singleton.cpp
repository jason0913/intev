#include <iostream>

using namespace std;

class Singleton
{
public:
	static Singleton * Instance()
	{
		if( 0== _instance)
		{
		       _instance = new Singleton();
		}
		return _instance;
	}
	//static Singleton * _instance;
private:
	Singleton()
	{
		cout<<"Initialize Singleton"<<endl;
	}
	virtual ~Singleton(void)
	{
		delete _instance;
		_instance = NULL;
		cout <<"Destroy Singleton"<<endl;
	}
    static Singleton * _instance;
};

Singleton* Singleton::_instance=NULL;

int main(int argc, char const *argv[])
{
	Singleton *s1 = Singleton::Instance();

	return 0;
}