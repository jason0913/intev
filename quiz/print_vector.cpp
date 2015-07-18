#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

void print(vector<int> v)
{
	cout <<"\nvector size:"<<v.size()<<endl;
	vector<int>::iterator p = v.begin();
}

int main(int argc, char const *argv[])
{
	vector<int> vec;
	vec.push_back(34);
	vec.push_back(23);
	print(vec);

	vector<int>::iterator p;
	p = vec.begin();
	*p = 68;
	*(p+1) = 70;
	print(vec);
	vec.pop_back();
	print(vec);
	vec.push_back(101);
	vec.push_back(102);

	int i=0;
	while(i <vec.size())
	cout<<vec[i++]<<" ";
	cout<<endl;

	vec[0] =1000;
	vec[1] =1001;
	vec[2] =1002;

	i =0;
	while(i <vec.size())
	{
		cout <<vec[i++]<<" ";
	}
	print(vec);
	return 0;
}