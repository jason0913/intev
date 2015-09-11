/* 
* @Author: jql
* @Date:   2015-07-28 07:43:36
* @Last Modified by:   jql
* @Last Modified time: 2015-07-28 08:10:59
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * GetMemory()
{
	char *p;
	p = (char *)malloc(100);
	strcpy(p,"hello world");
	return p;
}
void GetMemory(char **p)
{
	*p = (char *)malloc(100);
	strcpy(*p,"hello world");
}
// this is test way,but not
void GetMemory(char &p)
{
	p = (char *)malloc(100);
	strcpy(p,"hello world");
}
int main() {

	char *str = (char *)malloc(100);
	// char *str = NULL;
	// str = GetMemory();
	GetMemory(&str);
	printf("%s\n", str);
	free(str);
	char *str2;
	str2 = "damn string";
	printf("%s\n", str2);
    return 0;
}