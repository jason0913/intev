/* 
* @Author: root
* @Date:   2015-07-18 11:54:05
* @Last Modified by:   root
* @Last Modified time: 2015-07-19 02:37:41
*/

#include <iostream>

using namespace std;

char * LongestCommStr(char *str1,char *str2,char commstr[])
{
	if (NULL == str1 || NULL == str2)
	{
		return NULL;
	}
	char *ptr1 = str1;
	char *ptr2;
	char *pos;
	int maxlen =0;
	int commlen =0;
	while('\0' != *ptr1)
	{
		ptr2 = str2;
		commlen =0;
		while('\0' != *ptr2)
		{
			while((*ptr1 == *ptr2) &&('\0' != *ptr1) &&('\0' != *ptr2))
			{
				ptr1++,ptr2++,commlen++;
			}
			while((*ptr1 != *ptr2) && ('\0' != *ptr2))
				ptr2++;
			if (commlen > maxlen)
			{
				maxlen = commlen;
				pos = ptr1;
			}
		}
		ptr1 = str1++;
	}
	for (int i = 0; i < maxlen; ++i)
	{
		commstr[i] =*(pos +i);
	}
	return pos;
}
int main(){

	char str1[] ="abcad";
	char str2[] ="dgabc";
	char commstr[100];
	LongestCommStr(str1,str2,commstr);
	cout<<commstr<<endl;
    return 0;
}