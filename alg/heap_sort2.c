#include <stdio.h>
#include <stdlib.h>

void swap(int *x,int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void heapadjust2(int array[],int k,int m)
{
	int i =k;
	int j =2*i;
	int finish =0;
	int rc = array[k];
	int x = array[k];
	while(j <= m && !finish)
	{
		if (j<m && array[j]>array[j+1])
		{
			j++;
		}
		if (x <= array[j])
		{
			finish=1;
		}
		else
		{
			array[i]= array[j];
			i =j;
			j= 2*i;
		}
	}
	array[i]=rc;
}
void heapadjust(int array[],int i,int size)
{
	int lchild = 2*i+1;
	int rchild = 2*i+2;
	int max = i;
	if (i <= size/2)
	{
		if (array[max] < array[lchild] && lchild <= size)
		{
			max = lchild;
		}
		if (array[max] < array[rchild] && rchild <= size)
		{
			max = rchild;
		}
		if (i != max)
		{
			swap(&array[i],&array[max]);
			heapadjust(array,max,size);
		}
	}
}
void buildheap(int array[],int size)
{
	int i;
	for (i = size/2; i >=0; i--)
	{
		heapadjust(array,i,size);
	}
}

void heap_sort(int array[],int size)
{
	int i;
	buildheap(array,size-1);
	for (i =size-1; i >=0; i--)
	{
		swap(&array[0],&array[i]);
		heapadjust(array,0,i-1);
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
	int arr[]={16,7,3,20,17,8};
	int n = sizeof(arr)/sizeof(arr[0]);
	heap_sort(arr,n);
	print_arr(arr,n);
	return 0;
}