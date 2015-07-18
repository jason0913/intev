#include <iostream>
#include <map>

using namespace std;

long Fib(long n,map<long,long> my_map)
{
	long tmp;
	cout<<"step Fib func:"<<n<<endl;
	if (0 ==n || 1 ==n)
	{
		return 1;
	}
	else
	{
		map<long,long>::iterator it = my_map.find(n);
		if (my_map.end() ==it)
		{
			tmp = Fib(n-1,my_map) + Fib(n-2,my_map);
			my_map.insert(pair<long,long>(n,tmp));
			return tmp;
		}
		else
			return it->second;

	}
}



int main(int argc, char const *argv[])
{
	map<long,long> my_map;
	long n = 40;
	long res;
	res = Fib(n,my_map);
	cout<< "res ="<<res<<endl;
	return 0;
}