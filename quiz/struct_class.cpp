#include <iostream>

using namespace std;

enum BREED
{
	GOLDEN,CAIRN,DANDIE,LAB	
};

struct Mammal
{
	public:
		Mammal():age(2),weight(5){};
		~Mammal(){}; 

		int Getage()const
		{
			return age;
		}
		void Setage(int a)
		{
			age = a;
		}
		int Getweight()const
		{
			return weight;
		}
		void Setweight(int w)
		{
			weight =w;
		}

		void Mspeak()const
		{
			cout<<"Mammal speak"<<endl;
		}
		void Msleep()const
		{
			cout<<"Mammal sleep"<<endl;
		}
	protected:
		int age;
		int weight;
};

struct Dog :public Mammal
{
	public:
		Dog():itsbread(GOLDEN){};
		~Dog(){};

		void WagTail()const
		{
			cout<<"WagTail...."<<endl;
		}
		void Begfood()const
		{
			cout<<"Begfood....."<<endl;
		}
	private:
		BREED itsbread;
};

int main(int argc, char const *argv[])
{
	Dog fido;
	Mammal *base = &fido;
	// Mammal ma();
	Mammal ma;
	ma.Getage();
	base->Mspeak();
	fido.Mspeak();
	fido.WagTail();
	cout<<"fido age:"<<fido.Getage()<<endl;
	return 0;
}