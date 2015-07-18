/*
fibonacci by no recursion
*/
#include <stdio.h>

long long Fib(long long n)
{
	long long f1 = 1;
	long long f2 = 1;
	long long f3;
	long long i;
	for (i = 2; i < n; ++i)
	{
		f3 = f1 +f2;
		f1 = f2;
		f2 = f3;
		printf("f3 = %d ", f3);
	}
	return f3;
}


int main(int argc, char const *argv[])
{
	long long n = 49;
	long long res;
	res = Fib(n);
	printf("res = %d\n", res);
	return 0;
}