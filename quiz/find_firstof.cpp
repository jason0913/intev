/* 
* @Author: root
* @Date:   2015-07-14 07:42:45
* @Last Modified by:   root
* @Last Modified time: 2015-07-14 07:57:05
  trim the no alpha char in string
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
	string str1 ="//-----hello world----//";
	string str2; // A~Z a~z
	char p ='A';
	for (; p < 'Z'; ++p)
	{
		str2.push_back(p);
	}
	 p ='a';
	for (; p < 'z'; ++p)
	{
		str2.push_back(p);
	}
	// cout<<str2<<endl;
	int first = str1.find_first_of(str2);
	if (string::npos == first)
	{
		cout<<"not find any character"<<endl;
		return -1;
	}
	int last = str1.find_last_of(str2);
	if (string::npos == last)
	{
		cout<<"not find any character"<<endl;
		return -1;
	}
	cout<<str1.substr(first,last-first+1)<<endl;
    return 0;
}