/* 
* @Author: jql
* @Date:   2015-08-31 21:30:20
* @Last Modified by:   jql
* @Last Modified time: 2015-08-31 21:31:27
*/

#include <iostream>

using namespace std;

class A{
    public:
        A(){p();}
        virtual void p(){cout<<"A";}
        virtual ~A(){p();}
};
class B:public A{
    public:
        B(){p();}
        void p(){cout<<"B";}
        ~B(){p();}
};
int main(int, char**)
{
        A* a=new B();
        delete a;
}
