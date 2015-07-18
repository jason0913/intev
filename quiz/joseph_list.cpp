/* 
* @Author: root
* @Date:   2015-07-05 11:17:13
* @Last Modified by:   root
* @Last Modified time: 2015-07-05 11:35:51
*/

#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int Joseph(int n,int m)
{
	if (n <1 || m < 1)
	{
		return -1;
	}

	unsigned int i;
	list<int> numbers;
	for (i = 0; i < n; ++i)
	{
		numbers.push_back(i);
	}
	list<int>::iterator current = numbers.begin();

	while(numbers.size() >1)
	{
		for (int i = 0; i < m; ++i)
		{
			current++;
			if (current == numbers.end())
			{
				current = numbers.begin();
			}
		}
		list<int>::iterator next = ++current;
		if (next == numbers.end())
		{
			next = numbers.begin();
		}
		--current;
		numbers.erase(current);
		current = next;
	}
	return *(current);
}
int main(){

	int n =5;
	int m =3;
	int last;
	last = Joseph(n,m);
	cout<<"last:"<<last<<endl;
    return 0;
}