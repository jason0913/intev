/* 
* @Author: jql
* @Date:   2015-09-01 08:32:37
* @Last Modified by:   jql
* @Last Modified time: 2015-09-01 09:12:26
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){

	string st = "abc";
	cout<<st<<endl;
	st += 'e';
	cout<<st<<endl;
	for (int i = 0; i < 3; ++i)
	{
		char c;
		sprintf(&c,"%d",i);
		//itoa(i,&c,10);
		st += c;
		st.append(1,c);
	}
	cout<<st<<endl;
    return 0;
}