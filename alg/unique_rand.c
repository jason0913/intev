#include "alg.h"
#include <time.h>

#define SIZE 1000000
// global var is better than local(in stack limit),or local var by malloc(in heap)
// int num[SIZE];

void swap(int *a,int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
int main(int argc, char const *argv[])
{
	int n;
	int i,j;
	// int stack ,limit size
	// int num[SIZE]; 
	// in heap
	int *num = (int*)malloc(SIZE*sizeof(int));
	int total;
	total = atoi(argv[1]);
	if (2 != argc)
	{
		printf("Usage exe <num>\n");
		return -1;
	}
	if (total > SIZE)
	{
		printf("num to larger\n");
		return -1;
	}
	for (n = 0; n < total; ++n)
	{
		num[n] = n+1;
	}
	srand((unsigned)time(NULL));
	for (n = 0; n < total; n++)
	{
	/*	i = (rand()*total +rand())%total;
		j = (rand()*total +rand())%total;*/
		i = (rand())%total;
		j = (rand())%total;
		// printf("%d %d\n", i,j);
		swap(&num[i],&num[j]);
	}
	for (n = 0; n < total; ++n)
	{
		printf("%d ", num[n]);
	}
	free(num);
	return 0;
}