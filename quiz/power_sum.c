#include <stdio.h>

long power(int n)
{
	long res=1;
	int i;
	for (i = 0; i < n; ++i)
	{
		res = res *2;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int i;
	long sum = 0;
	for (i = 1; i <= 64; ++i)
	{
		printf("%ld \n", power(i));
		sum = sum + power(i);
	}
	printf("sum = %ld\n", sum);
	return 0;
}