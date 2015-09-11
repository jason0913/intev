/* 
* @Author: jql
* @Date:   2015-08-31 21:46:00
* @Last Modified by:   jql
* @Last Modified time: 2015-08-31 21:46:50
*/

#include <iostream>
#include <stdio.h>

using namespace std;

class A
{
public:
    void f()
    {
        printf("A\n");
    }
};

class B: public A
{
public:
    virtual void f()
    {
        printf("B\n");
    }
};

int main()
{
    A *a = new B;
    a->f();
    delete a;
    return 0;
}