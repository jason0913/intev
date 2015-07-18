#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 100

void RepalceSpace()
{
	char *str1 = "we are happy ";
	char *str3 = (char *)malloc(MAXLINE *sizeof(char));
	char *head = str3;

	printf("str1: %s\n", str1);
	unsigned int len;
	int i;
	len = strlen(str1);
	int leftlen =0;
	int rightlen =0;
	int space = 0;

	while('\0' != *str1)
	{
		if (' ' != *str1)
		{
			*str3++ = *str1++;
			leftlen++;
		}
		else
		{
			for (i = len + 3*space; i > leftlen+ space; --i)
			{
				*(str3+i +3) =*(str3 +i);
			}
			space++;
		}
	}
	printf("str3 %s\n", head);
}

int main(int argc, char const *argv[])
{
	char *str1 = " we are happy ";
	char *head1 = str1;
	char *str2 = (char *)malloc(MAXLINE *sizeof(char));
	char *str3 = (char *)malloc(MAXLINE *sizeof(char));
	char * head = str2;

	while('\0' != *str1)
	{
		if (' ' != *str1)
		{
			*str2++ = *str1++;
		}
		else
		{
			*str2 = '%';
			str2++;
			*str2 = '2';
			str2++;
			*str2 = '0';
			str2++;
			str1++;
		}
	}
	printf("before :%s\n", head1);
	printf("%s\n", head);
	printf("-------\n");
	RepalceSpace();
	printf("str3 %s\n", str3);
	return 0;
}