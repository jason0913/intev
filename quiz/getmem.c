#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * GetMemory(char *p,int num)
{
	p =(char *)malloc(sizeof(char)*num);
	if (NULL == p)
	{
		perror("malloc error");
	}
	return p;
}

int main(int argc, char const *argv[])
{
	char *str =NULL;
	str= GetMemory(str,100);
	strcpy(str,"hello");
	return 0;
}