#include <iostream>

class A
{
public:
	A(){};
	~A(){};
	int Getx() 
	{
		return x;
	}
	void Setx(int x)
	{
		this->x = x;
	}
private:
	int x;
};

int main(int argc, char const *argv[])
{
	const A consta;
	std::cout<<consta.Getx();
	return 0;
}