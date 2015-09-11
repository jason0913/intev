/* 
* @Author: jql
* @Date:   2015-08-22 23:50:39
* @Last Modified by:   jql
* @Last Modified time: 2015-08-23 00:04:35
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(const string &stra,const string &strb)
{
    int lena = stra.length();
    int lenb = strb.length();
    if(lena > lenb)
        return true;
    else
        return false;
}
void splitstring(string &str,vector<string> &dict)
{
	if (0 == str.length())
	{
		return;
	}
    sort(dict.begin(),dict.end(),compare);
    vector<string>::iterator iter;
    for(iter = dict.begin();iter != dict.end();iter++)
    {
        string temp(*iter);
        int len_temp = temp.length();
        int index =0;
        while((index = str.find(temp,index)) != string::npos)
        {
            // str.insert(index,' ');
            // str.insert(index+len_temp,' ');
        }
    }
    str.insert(str.length(),".");
    cout<<str<<endl;
}

int main(){

	string str="abrown fox";
    return 0;
}