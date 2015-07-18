#include <stdio.h>
#include <stdlib.h>

void swap(int *x,int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
struct Maxheap
{
	int size;
	int *array;
};
void maxif_heap(struct Maxheap *maxhp,int inx)
{ 
	int largest = inx;
	int left = (inx <<1)+1;
	int right = (inx+1)<<1;

	if (left < maxhp->size && maxhp->array[left] > maxhp->array[largest])
	{
		largest = left;
	}
	if (right < maxhp->size && maxhp->array[right] > maxhp->array[largest])
	{
		largest = right;
	}
	if (largest != inx)
	{
		swap(&maxhp->array[largest],&maxhp->array[inx]);
		maxif_heap(maxhp,largest);
	}
}
struct Maxheap * Creat_bulidheap(int *array,int size)
{
	int i;
	struct Maxheap *maxhp =
		(struct Maxheap *)malloc(sizeof(struct Maxheap));
	if (NULL == maxhp)
	{
		perror("malloc heap error");
		return;
	}
	maxhp->size = size;
	maxhp->array = array;
	for (i = (maxhp->size -2)/2; i >=0; i--)
	{
		maxif_heap(maxhp,i);
	}
	return maxhp;
}
void heap_sort(int array[],int size)
{
	struct Maxheap *maxhp = Creat_bulidheap(array,size);
	while(maxhp->size > 1)
	{
		swap(&maxhp->array[0],&maxhp->array[maxhp->size -1]);
		maxhp->size--;
		maxif_heap(maxhp,0);
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
	int arr[]={13,12,11,5,6,7};
	int n = sizeof(arr)/sizeof(arr[0]);
	heap_sort(arr,n);
	print_arr(arr,n);
	return 0;
}