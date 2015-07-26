/* 
* @Author: root
* @Date:   2015-07-25 10:39:26
* @Last Modified by:   root
* @Last Modified time: 2015-07-25 23:15:17
*/

#include <iostream>

using namespace std;

class Vechile
{
public:
	virtual void run() const
	{
		cout<<"Vechile run"<<endl;
	}
};

class Car :public Vechile
{
public:
	virtual void run() const
	{
		cout<<"car run"<<endl;
	}
};
class AirPlane:public Vechile
{
public:
	virtual void run()const
	{
		cout<<"AirPlane run"<<endl;
	}
};
void run_vechile(Vechile *pv)
{
	pv->run();
}
int main(){

	Vechile *pv;
	Car c1;
	AirPlane a1;

	pv = &c1;
	pv->run();
	pv->Vechile::run();
	pv = &a1;
	pv->run();
	pv->Vechile::run();
    return 0;
}