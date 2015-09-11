/* 
* @Author: jql
* @Date:   2015-08-08 10:44:33
* @Last Modified by:   jql
* @Last Modified time: 2015-08-08 10:57:58
  find longest substring
*/

#include <stdio.h>

int comlen(char *p,char *q)
{
	int len = 0;

	while(('\0' != *p && '\0' != *q) && (*p++ == *q++))
	{
		len++;
	}
	return len;
}

void LCSUB(char *str1,int len1,char *str2,int len2)
{
	if (NULL == str1 || NULL == str2 || len1 <= 0 || len2 <=0)
	{
		return;
	}
	int curlen,maxlen =0;
	int maxindex = -1;
	for (int i = 0; i < len1; ++i)
	{
		for (int j = 0; j < len2; ++j)
		{
			curlen = comlen(&str1[i],&str2[j]);
			if (curlen > maxlen)
			{
				maxlen = curlen;
				maxindex = i;
			}
		}
	}
	for (int i = 0; i < maxlen; ++i)
	{
		printf("%c ", str1[maxindex]);
		maxindex++;
	}
}
int main() {

	char str1[] = "aaaba";
	char str2[] = "abaa";
	int len1 = sizeof(str1)/(sizeof(str1[0]));
	int len2 = sizeof(str2)/(sizeof(str2[0]));
	LCSUB(str1,len1,str2,len2);
    return 0;
}