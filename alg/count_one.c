#include <stdio.h>

// count total 1 from 1 to N

int count_one(int n)
{
	int count = 0;
	while(0 !=n)
	{
		if (1 == n%10)
		{
			count++;
		}
		n = n/10;
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int i,N;
	int total = 0;
	printf("Inter N:\n");
	scanf("%d",&N);
	for (i = 1; i <= N; ++i)
	{
		total += count_one(i);
	}
	printf("total one from 1 to %d: %d\n", N,total);
	return 0;
}