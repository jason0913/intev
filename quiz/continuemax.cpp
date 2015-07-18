/* 
* @Author: root
* @Date:   2015-07-04 22:45:11
* @Last Modified by:   root
* @Last Modified time: 2015-07-04 23:14:53
  find continue max substr in str
*/

#include <iostream>
#include <string.h>

using namespace std;

int ContinueMax(char *str,char *substr)
{
	if (NULL == str)
	{
		return 0;
	}
	int len = strlen(str);
	int sublen =0;
	int maxlen =0;
	char *start,*end;
	char *sub_start,*sub_end;
	start = end =str;
	while('\0' != *start)
	{
		// start =end;
		while('\0' != *end)
		{
			// end++;
			if (*(end +1)== *end +1)
			{
				end++;
			}
			else
			{
				sublen = end - start+1; // len = end-start +1
				if (sublen > maxlen)
				{
					maxlen = sublen;
					sub_start = start;
					sub_end = end;
				}
				start = ++end;
				break;
			}
		}
	}
	char *ptr;
	ptr = sub_start;
	while(sub_start != sub_end)
	{
		*substr = *sub_start;
		sub_start++;
		substr++;
	}
	return maxlen;
}
int main(){

	char str[] = "abcd123456ed12345678";
	char substr[100];
	int maxlen;
	maxlen = ContinueMax(str,substr);
	cout<<"maxlen:"<<maxlen<< endl;
	cout<<substr<<endl;
    return 0;
}