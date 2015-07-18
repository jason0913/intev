/* 
* @Author: root
* @Date:   2015-06-30 08:36:31
* @Last Modified by:   root
* @Last Modified time: 2015-06-30 08:44:49
*/

#include <iostream>

using namespace std;

class Parent
{
public:
	Parent(int var =-1)
	{
		m_npub = var;
		m_npub = var;
		m_npub = var;
	}
public:
	int m_npub;
protected:
	int m_nptd;
private:
	int m_nprt;
};
class Child1:public Parent
{
public:
	int GetPub()
	{
		return m_npub;
	}
	int GetPtd()
	{
		return m_nptd;
	}
	int GetPrt()
	{
		return m_nprt;
	}
};
class Child2:protected Parent
{
public:
	int GetPub()
	{
		return m_npub;
	}
	int GetPtd()
	{
		return m_nptd;
	}
	int GetPrt()
	{
		return m_nprt;
	}
};
class Child3:private Parent
{
public:
	int GetPub()
	{
		return m_npub;
	}
	int GetPtd()
	{
		return m_nptd;
	}
	int GetPrt()
	{
		return m_nprt;
	}
};
int main(){

	Child1 cd1;
	Child2 cd2;
	Child3 cd3;

	int nvar =1;
	cd1.m_npub =nvar;
	cd1.m_nptd = nvar;
	nvar = cd1.GetPtd();

	cd2.m_npub = nvar;
	nvar = cd2.GetPtd();
	cd3.m_npub = nvar;
	nvar = cd3.GetPtd();
    return 0;
}