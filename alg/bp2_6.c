#include "stdio.h"

// count the num of 1 in binary num
int factorial(unsigned int n)
{
	if (1 ==n)
	{
		return 1;
	}
	else
		return n * factorial(n-1);
}
unsigned int count_suffix(int n)
{
	unsigned int count =0;
	while(0 == n %10)
	{
		count++;
		n = n/10;
	}
	return count;
}
int main(int argc, char const *argv[])
{
	unsigned int num;
	unsigned int factor;
	unsigned int suffix;
	printf("Input a num\n");
	scanf("%d",&num);
	factor = factorial(num);
	printf(" %d factorial is %d\n", num,factor);
	suffix = count_suffix(factor);
	printf("suffix 0 total: %d\n",suffix);
	return 0;
}