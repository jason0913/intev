#include <stdio.h>

long Fib(long n)
{
	printf("step Fib func: %d\n", n);
	if (0 >= n)
	{
		return 0;
	}
	if (1 == n)
	{
		return 1;
	}
	return Fib(n-1) + Fib(n-2);
}



int main(int argc, char const *argv[])
{
	long n = 49;
	long res;
	res = Fib(n);
	printf("res = %d\n", res);
	return 0;
}