/* 
* @Author: jql
* @Date:   2015-09-05 09:10:06
* @Last Modified by:   jql
* @Last Modified time: 2015-09-05 09:25:14
*/

#include <stdio.h>
#include <sring.h>

int maxlen =10;

char *strcombine1 = (char *) malloc(2 * 10 +1);
char *strcombine2 = (char *) malloc(2 * 10 +1);

void PrintMinNum(int *nums,int lenght)
{
	if (NULL == nums || lenght <0)
	{
		return;
	}

	char *strnums = (char *) malloc(sizeof(lenght));
	for (int i = 0; i < lenght; ++i)
	{
		strnums[i] = char[maxlen +1];
		sprintf(strnums[i],"%d",nums[i]);
	}
	qsort(strnums,lenght,sizeof(char*),compare);
	for (int i = 0; i < lenght; ++i)
	{
		printf("%s\n", strnums[i]);
	}
	for (int i = 0; i < lenght; ++i)
	{
		free(strnums);
	}
}

int compare(void * strnum1,void *strnum2)
{
	strcpy(strcombine1,*(char **)strnum1);
	strcat(strcombine1,*(char **)strnum2);

	strcpy(strcombine2,*(char **)strnum2);
	strcat(strcombine2,*(char **)strnum1);

	return strcmp(strcombine1,strcombine2);
}
int main() {

    return 0;
}