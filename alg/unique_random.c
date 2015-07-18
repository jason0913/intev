#include <stdio.h>
#include <stdlib.h>

#ifndef RAND_INT
#define RAND_INT 100
#endif

int rand_nums[RAND_INT];

int main(int argc, char const *argv[])
{
	srand((unsigned)time(NULL));
	memset(rand_nums,0,sizeof(rand_nums));

	int m=0;
	int i;
	for (i = 0; i < 10; ++i)
	{
		while(!rand_nums[m = rand() % RAND_INT +1])
		{
			rand_nums = i;
		}
	}

	return 0;
}