/* 
* @Author: jql
* @Date:   2015-07-28 08:10:16
* @Last Modified by:   jql
* @Last Modified time: 2015-07-28 08:13:52
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

void GetMemory(String &p)
{
	p = (char *)malloc(100);
	strcpy(p,"hello world");
}
int main(){

	char *str = NULL;
	GetMemory(str);
	printf("%s\n", str);
    return 0;
}