/* 
* @Author: jql
* @Date:   2015-07-28 08:16:56
* @Last Modified by:   jql
* @Last Modified time: 2015-07-28 08:20:52
*/

#include <stdio.h>
#include <string.h>

int main() {

	char str1[10],str2[10];
	int i;
	for (int i = 0; i < 10; ++i)
	{
		str1[i] ='a';
	}
	// str1[9] ='\0';
	printf("%s\n", str1);
	strcpy(str2,str1);
	printf("%s\n", str2);
    return 0;
}