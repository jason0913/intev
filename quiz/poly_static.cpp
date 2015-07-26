/* 
* @Author: root
* @Date:   2015-07-25 10:39:26
* @Last Modified by:   root
* @Last Modified time: 2015-07-25 22:34:50
*/

#include <iostream>
// #include <template>

using namespace std;

class Vechile
{
public:
	void run() const
	{
		cout<<"Vechile run"<<endl;
	}
};

class Car :public Vechile
{
public:
	void run() const
	{
		cout<<"car run"<<endl;
	}
};
class AirPlane:public Vechile
{
public:
	void run()const
	{
		cout<<"AirPlane run"<<endl;
	}
};
template <typename T>
void run_vechile(T veh)
{
	veh.run();
}
int main(){

	Vechile v1;
	Car c1;
	AirPlane a1;
	run_vechile(c1);
	run_vechile(a1);
	c1.Vechile::run();
	a1.Vechile::run();
    return 0;
}