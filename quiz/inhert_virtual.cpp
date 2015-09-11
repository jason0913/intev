/* 
* @Author: jql
* @Date:   2015-08-31 22:25:20
* @Last Modified by:   jql
* @Last Modified time: 2015-08-31 22:25:43
*/

#include <iostream>

using namespace std;

class Base
{
    int x;
public:
    Base(int b): x(b) {}
    virtual void display()
    {
        cout << x;
    };
};
class Derived: public Base
{
    int y;
public:
    Derived(int d): Base(d), y(d) {} void display()
    {
        cout << y;
    }
};

int main()
{
    Base b(1);
    Derived d(2);
    Base *p = & d;
    b.display();
    d.display();
    p->display();
    return 0;
}