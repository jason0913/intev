#include "ds.h"

// the last else exec

int main(int argc, char const *argv[])
{
	int a =2;

	if (2 == a)
	{
		printf("a =2\n");
	}
	if (1 == a)
	{
		printf("a =1\n");
	}
	else
	{
		printf("not else if,exec\n");
	}
	return 0;
}