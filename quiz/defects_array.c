#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test1()
{
	char string[10];
	char *str1 = "0123456789";
	strcpy(string,str1);
	printf("%s\n", string);
}

void test2()
{
	char string[10],str1[10];
	int i;
	for (i = 0; i < 10; i++)
	{
		str1[i] = 'a';
	}
	printf("%d\n", i);
	printf("%s\n", str1);
	str1[i-1] ='\0';
	strcpy(string,str1);
	printf("%s\n", string);
}

int main(int argc, char const *argv[])
{
	test1();
	test2();
	return 0;
}
