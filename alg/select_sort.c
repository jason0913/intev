#include "stdio.h"

void swap(int *x,int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
void select_sort(int a[],int n)
{
	int i,j;
	int min_index;
	for (i = 0; i < n-1; ++i)
	{
		min_index =i;
		for (j = i; j < n; ++j)
		{
			if (a[j] < a[min_index])
			{
				min_index =j;
			}
		}
		swap(&a[i],&a[min_index]);
	}
}

int main(int argc, char const *argv[])
{
	int a[] = {64,25,12,22,11};
	int n,i;
	n = sizeof(a)/sizeof(a[0]);
	select_sort(a,n);
	for (i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}