/*
move the odd in the front of arr,
even int the end
*/
#include <stdio.h>
#include <stdlib.h>

void RecordOddEven(int arr[],int len)
{
	if (NULL == arr || len <=0)
	{
		printf("invalid para\n");
		exit(-1);
	}
	int i,j;
	int tmp;
	for (i = 0; i < len; ++i)
	{
		if (0 == arr[i] %2)
		{
			tmp = arr[i];
			for (j = i; j < len-1; ++j)
			{
				arr[j] = arr[j+1];
			}
			arr[j] = tmp;
		}
	}
}

void swap(int *a,int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;

}
void RecordOddEven2(int arr[],int len)
{
	int right;
	int left;
	int tmp;
	right = len -1;
	left = 0;

	while(left <= right)
	{
		while(1 == arr[left]%2)
		{
			if (left <= right)
			{
				left++;
			}
		}
		tmp = arr[left];
		while(0 == arr[right]%2)
		{
			if (left <= right)
			{
				right--;
			}
		}
		if (left <= right)
		{
			swap(&arr[left],&arr[right]);
			left++;
			right--;
		}
	}
}void RecordOddEven3(int arr[],int len)
{
	int right;
	int left;
	int tmp;
	right = len -1;
	left = 0;

	while(left <= right)
	{
		while((1 == arr[left]%2) && (left <= right))
		{
			left++;
		}
		while(0 == arr[right]%2 && (left <= right))
		{
			right--;
		}
		if (left <= right)
		{
			swap(&arr[left],&arr[right]);
			left++;
			right--;
		}
	}
}
int main(int argc, char const *argv[])
{
	int arr[] = {1,2,3,4,5,6};
	int len,i;
	len = sizeof(arr)/sizeof(arr[0]);
	// RecordOddEven(arr,len);
	RecordOddEven2(arr,len);
	for (i = 0; i < len; ++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}