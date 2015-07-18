#include "ds.h"

#define SIZE 10
// func which return a point to mult arr eg:int (*p)[SIZE]
int (*paf())[SIZE] 
{
	int (*pear)[SIZE];
	int i;
	// allocate at heap,func retrun will exist
	pear = malloc(SIZE*sizeof(int));
	for (i = 0; i < SIZE; ++i)
	{
		(*pear)[i] = i;
	}
	return pear;
}
// return array by using point
char *var_stack()
{
	// allocate at stack,var_stack return will dispear, in case that :static
	char arr[SIZE] ={'a','b','c'};
	return arr;
}

char *var_heap()
{
	// allocate at heap,
	char *pheap = malloc (SIZE*sizeof(char));
	printf("sizeof(char *) %d\n", sizeof(pheap));
	snprintf(pheap,SIZE*sizeof(char),"local var at heap");
	return pheap;
}
int main(int argc, char const *argv[])
{
	int (*result)[SIZE];
	int i;
	char *ptr;
	char *ptr_heap;

	result = paf();
	for (i = 0; i < SIZE; ++i)
	{
		printf("(*result)[%d] = %d\n", i,(*result)[i]);
	}
	ptr = var_stack();
	ptr_heap = var_heap();
	printf("return arr %s\n", ptr);
	printf("return pheap %s\n", ptr_heap);
	return 0;
}