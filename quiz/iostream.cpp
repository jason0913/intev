#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	istream_iterator<int> cin_os(cin);
	istream_iterator<int> eof;
	ostream_iterator<int> cout_os(cout,",");

	vector<int> vec(cin_os,eof);
	
	sort(vec.begin(),vec.end());
	unique_copy(vec.begin(),vec.end(),cout_os);

	return 0;
}