#include "stdio.h"

// insert sort
void insert_sort(int a[],int n)
{
	int tmp;
	int i,j;
	for (i = 1; i < n; ++i)
	{
		tmp = a[i];
		for (j = i-1; j >=0; j--)
		{
			if (a[j] > tmp)
			{
				a[j+1] = a[j];
			}
			else
				break;
		}
		a[j+1] = tmp;	
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
	insert_sort(a,n);
	print_arr(a,n);
	return 0;
}