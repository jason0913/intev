/*
genrics function
*/
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
const T* MyFind(T *array,T n,T num)
{
	const T *p = array;
	T i;
	for (i = 0; i < n; ++i)
	{
		if (*p == num)
		{
			return p;
		}
		++p;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int array[] ={1,2,3};
	int n =sizeof(array)/sizeof(array[0]);
	const int *p;
	p =MyFind(array,n,2);
	cout <<*p<<endl;
	return 0;
}