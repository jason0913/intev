/* 
* @Author: jql
* @Date:   2015-08-31 21:52:30
* @Last Modified by:   jql
* @Last Modified time: 2015-08-31 21:55:03
  member func call virtual func
*/

#include <iostream>

using namespace std;

class Base {
    public:
    Base(int j): i(j)  {}
    virtual~Base() {}
    void func1() {
        i *= 10;
        func2();
    }
    int getValue() {
        return  i;
    }
    protected:
    virtual void func2() {
    	cout<<"call Base::func2 "<<endl;
        i++;
    }
    protected:
    int i;
};
class Child: public Base {
    public:
    Child(int j): Base(j) {}
    void func1() {
        i *= 100;
        func2();
    }
    protected:
    void func2() {
    	cout<<"calll Child::func2"<<endl;
        i += 2;
    }
};
int main() {
    Base * pb = new Child(1);
    pb->func1();
    cout << pb->getValue() << endl; delete pb;
}