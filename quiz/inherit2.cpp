/* 
* @Author: root
* @Date:   2015-06-30 07:57:52
* @Last Modified by:   root
* @Last Modified time: 2015-06-30 08:28:03
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
protected:
	int color;
};
class Giraffe:public Animal
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
	int getcolor()
	{
		return color;
	}
};

void Func2(Giraffe &an)
{
	an.take();
}
int main(){
	Giraffe gir;
	gir.take();
	// gir.eat();
	gir.getcolor();
    return 0;
}