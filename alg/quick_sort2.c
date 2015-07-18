#include <stdio.h>

void swap(int *x,int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

int partition(int arr[],int l,int h)
{

}

void quick_sort(int arr[], int l, int h)
{
	int p;
	if (l <h)
	{
		p = partition(arr,l,h);
		quick_sort(arr,l,p-1);
		quick_sort(arr,p+1,h);
	}
}
void print_arr(int arr[],int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	int arr[] ={10,7,8,9,1,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	quick_sort(arr,0,n);
	print_arr(arr,n);
	return 0;
}