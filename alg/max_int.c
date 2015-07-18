#include "alg.h"

int main(int argc, char const *argv[])
{
	int i= 2;
	int j;
	int a[100000000];
	while(i >0)
	{
		printf("%d \n", i);
		i = 2*i;
	}
	for (j = 0; j < 100000000; ++j)
	{
		a[j] = j;
	}
	return 0;
}