#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char str1[] = "hello world";
	char str2[] = "hello world";
	char *str3 = "hello world";
	char *str4 = "hello world";
	char *str5 = "hello world";

	if (str1 == str2)
	{
		printf("str1 same str2\n");
	}
	else
		printf("str1 not same str2\n");
	printf("str1 = %x, str2 = %x\n", str1,str2);
	if (str3 == str4)
	{
		printf("str3 same str4\n");
	}
	else
		printf("str3 not same str4\n");
	printf("str3 = %x, str4 = %x,str5 =%x\n", str3,str4,str5);
	return 0;
}