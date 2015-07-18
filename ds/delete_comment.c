#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1024

int main(int argc, char const *argv[])
{
	char buf[MAXLINE],*ptr;
	FILE *fp,*fp2;
	int i;

	fp = fopen("commt.c","r");
	if (fp == NULL)
	{
		perror("open file fail");
		exit(-1);
	}
	fp2 = fopen("commt2.c","w");
	if (fp2 == NULL)
	{
		perror("open file2 fail");
		exit(-1);
	}
	while(fgets(buf,sizeof(buf),fp) != NULL)
	{
		ptr = strstr(buf,"//");
		// printf("ptr %s\n", ptr);
		if (NULL != ptr)
		{
			buf[0] ='\0';
		}
		fputs(buf,fp2);
	}
	return 0;
}