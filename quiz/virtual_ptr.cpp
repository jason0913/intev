/* 
* @Author: jql
* @Date:   2015-08-20 22:41:04
* @Last Modified by:   jql
* @Last Modified time: 2015-08-20 22:51:56
*/

#include <iostream>

using namespace std;

class animal
{
protected:
    int age;
public:
    virtual void print_age(void) = 0;
};
class dog :public animal
{
public:
       dog() {this -> age = 2;}
       ~dog() { }
       virtual void print_age(void) {cout<<"Wang, my age = "<<this -> age<<endl;}
};
class cat :public animal
{
public:
    cat() {this ->age = 1;}   ~cat() {}
    virtual void print_age(void) {cout<<"Miao,my age = "<<this -> age<<endl;}
};
int main(void)
{
     cat kitty;
     dog jd;
     animal * pa;
     int * p = (int *)(&kitty);
     int * q = (int *)(&jd);
    p[0] = q[0];
    // p[0] = q[0];
    pa = &kitty;
    pa -> print_age();
    return 0;
}