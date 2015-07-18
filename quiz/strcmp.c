#include <stdio.h>
#include <stdlib.h>

// 比较两个字符串大小
int mystrcmp(char *src,char * dst)
{
	
	for ( ; *src == *dst && *src != '\0' && *dst != '\0'; )
		src++,dst++;
	if (*src =='\0' && *dst == '\0')
	{
		return 0;
	} else
	{
		return *src - *dst;
	}	
}

int main(int argc, char* argv[]) 
{
	char str1[10];
	char str2[10];
	int res;
	printf("Input str1:\n");
	fgets(str1,sizeof(str1),stdin);
	printf("Input str2:\n");
	fgets(str2,sizeof(str2),stdin);
	res = mystrcmp(str1,str2);
	printf("res = %d\n",res);
	if (res == 0)
	{
		printf("str1 == str2\n");
	}
	if (res > 0)
	{
		printf("str1 > str2\n");
	} 
	if (res < 0)
	{
		printf("str1 < str2\n");
	} 
	return 0;
}