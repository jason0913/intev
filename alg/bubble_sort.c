#include "stdio.h"

// bubble sort
void swap(int *x,int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
void bubble_sort(int a[],int n)
{
	int i,j;
	int swaped;
	for (i = 0; i < n-1; ++i)
	{
		swaped =0;
		for (j = 0; j < n-i-1; ++j)
		{
			if (a[j] > a[j+1])
			{
				swap(&a[j],&a[j+1]);
				swaped =1;
			}
		}
		if (0 == swaped)
		{
			break;
		}
	}
}
void print_arr(int a[],int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
}
int main(int argc, char const *argv[])
{
	int a[] = {5,1,4,2,8};
	int n,i;
	n = sizeof(a)/sizeof(a[0]);
	bubble_sort(a,n);
	print_arr(a,n);
	return 0;
}