#include <iostream>

using namespace std;

class CAT
{
public:
	CAT(int age):itsage(age)
	{
		Howmany++;
	};
	virtual ~CAT()
	{
		Howmany--;
	}
	virtual int Getage()const
	{
		return itsage;
	}
	virtual void Setage(int age)
	{
		itsage = age;
	}
	static int Gethowmany()
	{
		return Howmany;
	}
	static int Howmany;
private:
	int itsage;
};

int CAT::Howmany = 0;

class A
{

	// static const int size =0;
	const int size =0;
};
int main(int argc, char const *argv[])
{
	const int MaxCats = 5;
	int i;
	CAT * CAthouse[MaxCats];
	for (int i = 0; i < MaxCats; ++i)
	{
		CAthouse[i] =  new CAT(i);
	}
	for (int i = 0; i < MaxCats; ++i)
	{
		cout<<"static func:"<<CAT::Gethowmany()<<endl;
		cout<<"there are "<<CAT::Howmany<<endl;
		cout<<CAthouse[i]->Getage()<<" years odl;"<<endl;
		cout<<"delete cat"<<endl;

		delete CAthouse[i];
		CAthouse[i] =0;
	}
	return 0;
}