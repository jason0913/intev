/* 
* @Author: root
* @Date:   2015-06-30 07:57:52
* @Last Modified by:   root
* @Last Modified time: 2015-06-30 08:11:16
*/

#include <iostream>

using namespace std;

class Animal
{
public:
	Animal(){};
	~Animal(){};
	void eat()
	{
		cout<<"Animal eat"<<endl;
	}
};
class Giraffe:private Animal
{
public:
	Giraffe(){};
	~Giraffe(){};
	void strech_neck()
	{
		cout<<"Giraffe strech_neck"<<endl;
	}
	void take()
	{
		eat();
	}
};
class Cat:public Animal
{
public:
	Cat(){};
	~Cat(){};
	void meaw()
	{
		cout<<"Cat meaw"<<endl;
	}
};
void Func( Animal &an)
{
	an.eat();
}
void Func2(Giraffe &an)
{
	an.take();
}
int main(){
	Cat dao;
	Giraffe gir;
	Func(dao);
	Func2(gir);
    return 0;
}