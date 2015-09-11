/* 
* @Author: jql
* @Date:   2015-08-18 03:43:28
* @Last Modified by:   jql
* @Last Modified time: 2015-08-19 00:49:25
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

	vector<string> vec;
	string str;
	while(getline(cin,str))
	{
		if (str.empty())
		{
			cout<<"cin end"<<endl;
			break;
		}
		vec.push_back(str);
	}
	vector<string>::iterator it = vec.begin();
	for (; it < vec.end(); ++it)
	{
		cout<<*it<<endl;
	}
    return 0;
}