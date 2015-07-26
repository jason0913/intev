/* 
* @Author: root
* @Date:   2015-07-26 10:18:58
* @Last Modified by:   root
* @Last Modified time: 2015-07-26 10:35:34
*/

#include <iostream>

using namespace std;

class Cobj
{
public:
	virtual void Serialize()
	{
		cout<<"Cobj Serialize"<<endl;
	}
};
class Cdoc:public Cobj
{
public:
	int m_data;
	virtual void Serialize()
	{
		cout<<"Cdoc Serialize"<<endl;
	}
};
class MyDoc:public Cdoc
{
public:
	int m_data2;
	MyDoc(){m_data2 =0;}
	MyDoc(Cdoc &doc)
	{
		m_data2 =0;
	}
	void func()
	{
		cout<<"MyDoc func"<<endl;
		Serialize();
	}
	virtual void Serialize()
	{
		cout<<"MyDoc Serialize"<<endl;
	}
};
int main(){

	Cdoc doc;
	((MyDoc)doc).func();  //base to dirved
	cout<<"--------"<<endl;
	Cobj *ptr;
	MyDoc mydoc;
	ptr = &mydoc;
	ptr->Serialize();
	// ptr->Cdoc::Serialize();
	ptr->Cobj::Serialize();
    return 0;
}