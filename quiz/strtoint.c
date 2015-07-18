#include <stdio.h>
#include <string.h>

int StrotInt(char *str)
{
	int number =0;

	if (NULL == str)
	{
		return 0;
	}

	while('\0' !=*str)
	{
		number = number *10 + *str -'0';
		str++;
	}
	return number;
}
int main(int argc, char const *argv[])
{
	// char *str = "1234";
	char *str = NULL;
	int number;
	number = StrotInt(str);
	printf("%d\n", number);
	return 0;
}