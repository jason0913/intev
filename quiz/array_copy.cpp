/* 
* @Author: root
* @Date:   2015-07-14 08:01:26
* @Last Modified by:   root
* @Last Modified time: 2015-07-14 08:04:54
*/

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main(){

	char str1[10];
	char str2[10];
	int i;
	for (i = 0; i < 10; ++i)
	{
		str1[i] ='a';
	}
	// str1[i] ='\0';
	strcpy(str2,str1);
	cout<<str2<<endl;

	char *p = (char*)malloc(100);
	cout<<"sizeof(p):"<<sizeof(p)<<endl;
    return 0;
}