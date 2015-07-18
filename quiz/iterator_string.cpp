#include <iostream>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
	string s("hiya!");
	string::iterator iter = s.begin();
	while(iter != s.end())
	{
		cout<<*iter++<<"";
	}
	cout<<"------"<<endl;
	iter = s.begin();
	while(iter != s.end())
	{
		*iter = toupper(*iter);
		cout<<*iter++<<"";
	}
	cout<<s.substr(2,2)<<endl;
	cout<<s.substr().append("end")<<endl;
	string::size_type pos;
	pos=s.find("end");
	cout<< pos<<endl;
	return 0;
}