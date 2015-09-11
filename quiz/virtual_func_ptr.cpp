/* 
* @Author: jql
* @Date:   2015-08-22 04:45:42
* @Last Modified by:   jql
* @Last Modified time: 2015-08-22 04:48:58
*/

#include <iostream>

using namespace std;

class CParent
{
public:
	virtual void Intro()
	{
		cout<<"CParent "<<endl;
		Hobby();
	}
	virtual void Hobby()
	{
		cout<<"Like football"<<endl;
	}
};
class CChild:public CParent
{
public:
	virtual void Intro()
	{
		cout<<"CChild "<<endl;
		Hobby();
	}
	virtual void Hobby()
	{
		cout<<"Like basketball"<<endl;
	}
};
int main(){

	CChild *pb =new CChild();
	CParent *pa = (CParent *)pb;
	pa->Intro();
    return 0;
}