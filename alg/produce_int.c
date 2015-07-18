#include "alg.h"

int main(int argc, char const *argv[])
{
	int i;
	int total;
	total = atoi(argv[1]);
	// below is error
	// total = (int)(argv[1]);
	for (i = total; i > 0; i--)
	{
		// printf("%d,", i);
		// produce data with ","
		printf("%d ", i);
	}
	return 0;
}
