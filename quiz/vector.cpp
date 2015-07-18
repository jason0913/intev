#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
	const vector<string>::size_type size = 10;
	std::vector<string> vec(size,"ch");
	// cout<< vec<<endl;
	for (vector<string>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
	{
		cout<<*iter<<endl;
	}
	return 0;
}