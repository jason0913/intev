/* 
* @Author: jql
* @Date:   2015-09-01 22:37:02
* @Last Modified by:   jql
* @Last Modified time: 2015-09-02 02:54:55
  josephy loop
*/

#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main(){

	list<int> loop;
	int n =5,m =3;
	for (int i = 0; i < n; ++i)
	{
		loop.push_back(i);
	}
	list<int>::iterator iter = loop.begin();
	for (; iter != loop.end(); ++iter)
	{
		cout<<*iter<<" ";
	}
	cout<<endl;
	while(loop.size() >0)
	{
		for (int j = 0; j < m; ++j)
		{
			iter++;
			if(iter == loop.end())
			{
				iter = loop.begin();
			}
		}
		list<int>::iterator next = ++iter;
		if (next == loop.end())
		{
			next = loop.begin();
		}
		--iter; //remove and run
		cout<<*iter<<" ";
		loop.remove(*iter);
		iter = next;
	}
    return 0;
}