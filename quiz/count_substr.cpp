/* 
* @Author: root
* @Date:   2015-07-16 22:02:58
* @Last Modified by:   root
* @Last Modified time: 2015-07-16 22:09:21
  count the substr
*/

#include <iostream>
#include <string.h>

using namespace std;

int main(){

	int count =0;
	char *str ="abccab";
	char *sub ="ab";
	char *ptr = str;
	int len = strlen(sub);
	while('\0' != *ptr)
	{
		if (0== strncmp(ptr,sub,len))
		{
			count++;
			ptr = ptr+len;
		}
		else
			ptr++;
			
	}
	cout<<"count substr:"<<count<<endl;
    return 0;
}