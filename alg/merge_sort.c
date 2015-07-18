#include "stdio.h"

// insert sort
void merge(int arr[],int l,int m,int r);

void merge_sort(int arr[],int l,int r)
{
	int mid;
	if (r > l)
	{
		mid = (l + r)/2;
		merge_sort(arr,l,mid);
		merge_sort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}
void merge(int arr[],int l,int m,int r)
{
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;

	int L[n1],R[n2];

	for (i = 0; i < n1; ++i)
	{
		L[i] = arr[l+i];
	}
	for (j = 0; j < n2; ++j)
	{
		R[j] = arr[m+1+j];
	}

	i =j=0;
	// this is important,k start index
	k = l;
	while(i <n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++,k++;
		}
		else if (L[i] > R[j])
		{
			arr[k] = R[j];
			j++,k++;
		}
	}

	while(i < n1)
	{
		arr[k] = L[i];
		k++,i++;
	}
	while(j <n2)
	{
		arr[k] = R[j];
		k++,j++;
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
	int a[] = {5,1,4,2};
	int n,i;
	n = sizeof(a)/sizeof(a[0]);
	merge_sort(a,0,n-1);
	print_arr(a,n);
	return 0;
}