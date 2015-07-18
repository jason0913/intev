#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
	string word;
	map<string, int> word_count;
	word_count["james"] = 10;
	while(cin >> word)
	{

		++word_count[word];
	}
	map<string,int>::iterator iter = word_count.begin();
	while(word_count.end() != iter)
	{
		cout<< iter->first<<" " ;
		cout<< iter->second;
		iter++;
		cout <<endl;
	}
	cout<<word_count.erase("james");
	cout<<"-------"<<endl;
	std::vector<int> ivec;
	for (vector<int>::size_type i = 0; i < 10; ++i)
	{
		ivec.push_back(i);
		ivec.push_back(i);
	}
	set<int> iset(ivec.begin(),ivec.end());
	cout<< ivec.size() <<" "<< iset.size()<<endl;
	return 0;
}