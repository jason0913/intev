/* 
* @Author: root
* @Date:   2015-07-16 22:13:50
* @Last Modified by:   root
* @Last Modified time: 2015-07-16 22:22:05
  imply the lib sunc strstr
*/

#include <iostream>
#include <string.h>

using namespace std;

char * mystrstr(char *str1,const char *sub)
{
	if (NULL == str1 || NULL == sub)
	{
		return NULL;
	}
	char *ptr = str1;
	int len = strlen(sub);
	while('\0' != *ptr)
	{
		if (0 == strncmp(ptr,sub,len))
		{
			return ptr;
		}
		else
			ptr++;
	}
	return NULL;
}
int main(){

	char *str1 = "abcdss";
	char *sub = "cd";
	char *pos;
	pos = mystrstr(str1,sub);
	cout<<pos<<endl;

    return 0;
}