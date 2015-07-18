#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 交换字符串的前后半部分

int main(int argc, char* argv[]) 
{	
	int len = 0;
	char* p = (char*)malloc(100*sizeof(char));
	char* tmp = (char*)malloc(50*sizeof(char));
	printf("Enter string:\n");
	gets(p);
	printf("original: %s\n",p);
	len = strlen(p);
	if (len %2 == 0)
	{
		memcpy(tmp ,p ,len / 2);
		memcpy(p ,p + len / 2 ,len / 2);
		strcpy(p + len / 2 ,tmp);
	} else
	{
		memcpy(tmp ,p ,len / 2);
		memcpy(p ,p + len / 2 + 1 ,len / 2);
		strcpy(p + len / 2 + 1 ,tmp);
	}
	printf("move half: %s\n",p);
	return 0;
}