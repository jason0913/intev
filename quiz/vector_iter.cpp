#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> v)
{
	cout << "vector size:"<<v.size()<<endl;
}

int main(int argc, char const *argv[])
{
	vector<int> array;
	array.push_back(1);
	array.push_back(6);
	array.push_back(6);
	array.push_back(2);

	vector<int>::iterator itor;
	vector<int>::iterator itor2;

	for (itor = array.begin(); itor != array.end();)
	{
		if (6 == *itor)
		{
			itor2 = itor;
			// array.erase(itor2);
			array.erase(remove(array.begin(),array.end(),6),array.end());
			// itor--;
		}
		itor++;
	}
	print(array);
	return 0;
}