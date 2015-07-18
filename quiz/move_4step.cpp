/* 
* @Author: root
* @Date:   2015-07-14 08:25:31
* @Last Modified by:   root
* @Last Modified time: 2015-07-14 08:43:28
  replace \t with 4 * in string
*/

#include <iostream>
#include <string.h>

using namespace std;

int main(){

	char str[100] ="abc\tefg\tdone";
	char *ptr;
	ptr = str;
	while('\0' != *ptr)
	{
		if ('\t' == *ptr)
		{
			char *last;
			for (int i = 0; i < 4; ++i)
			{
				int len = strlen(str);
				for (last = str+len; last >ptr+i ; last--)
				{
					*(last+1) = *last;
				}
				*last ='-';
			}
			while(ptr <last)
			{
				*ptr ='*';
				ptr++;
			}
		}
		ptr++;
	}
	cout<<str<<endl;
    return 0;
}