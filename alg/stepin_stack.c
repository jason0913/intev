#include <stdio.h>
#include <stdlib.h>

void factorial(int n)
{
	if (1==n)
	{
		return;
	}
	else
		factorial(n-1);
	printf("in factorial %d\n", n);
}

int main(int argc, char const *argv[])
{
	int n =3;
	factorial(n);
	return 0;
}