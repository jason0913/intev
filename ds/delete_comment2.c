#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*the program to delete commenter in the source*/

#define MAXLINE 1024

int main(int argc, char const *argv[])
{
	char buf[MAXLINE],*ptr,*ptr2,*ptr3;
	FILE *fp,*fp2;
	int i;
	int flag =0;
	char srcfile[MAXLINE];
	char dstfile[MAXLINE];

	printf("Input source file\n");
	scanf("%s",srcfile);
	printf("Input dstfile file\n");
	scanf("%s",dstfile);
	fp = fopen(srcfile,"r");
	if (fp == NULL)
	{
		perror("open file fail");
		exit(-1);
	}
	fp2 = fopen(dstfile,"w");
	if (fp2 == NULL)
	{
		perror("open file2 fail");
		exit(-1);
	}
	while(fgets(buf,sizeof(buf),fp) != NULL)
	{
		ptr = strstr(buf,"/*");
		ptr2 = strstr(buf,"*/");
		ptr3 = strstr(buf,"//");
		// printf("ptr %s\n", ptr);
		if (NULL != ptr3)
		{
			buf[0] ='\0';
		}
		// printf("ptr %s\n", ptr);
		if (NULL != ptr)
		{
			flag =1;
		}
		if (NULL != ptr2)
		{
			flag =0;
			buf[0] = '\0';
		}
		if (1 ==flag)
		{
			buf[0] ='\0';
		}
		fputs(buf,fp2);
	}
	return 0;
}