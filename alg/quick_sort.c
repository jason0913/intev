#include <stdio.h>

void swap(int *x,int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

int partition(int arr[],int left,int right)
{
	int pivot;
	pivot =arr[left];
	while(left < right)
	{
		while(arr[right] > pivot && left < right)
			right--;
		// if (arr[right] <pivot)
		if (left <right)
		{
			arr[left] =arr[right] ;
			left++;
		}
		while(arr[left] <pivot && left < right)
			left++;
		// if (arr[left] > pivot)
		if (left <right)
		{
			arr[right] = arr[left];
			right--;
		}
	}
	arr[left] = pivot;
	return left;
}

void quick_sort(int arr[],int left,int right)
{
	int p;
	if (left < right)
	{
		p = partition(arr,left,right);
		quick_sort(arr,left,p-1);
		quick_sort(arr,p+1,right);
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
	quick_sort(arr,0,n-1);
	print_arr(arr,n);
	return 0;
}