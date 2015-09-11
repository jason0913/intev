/* 
* @Author: jql
* @Date:   2015-08-31 21:40:59
* @Last Modified by:   jql
* @Last Modified time: 2015-08-31 21:43:51
*/

#include <iostream>
#include <stdio.h>

using namespace std;

class A
{
public:
    A()
    {
        printf("A ");
    }
    /*virtual*/
    // ~A()
    virtual ~A()
    {
        printf("deA ");
    }
};

class B
{
public:
    B()
    {
        printf("B ");
    }
    ~B()
    {
        printf("deB ");
    }
};
// constructor order is determine by inilialize
class C: public B, public A
{
public:
    C()
    {
        printf("C ");
    }
    ~C()
    {
        printf("deC ");
    }
};
int main()
{
    A *a = new C();
    delete a;
    return 0;
}
