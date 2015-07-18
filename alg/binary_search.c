#include "stdio.h"

// normal search and binary_search
int search(int a[],int n, int x)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		if (x == a[i])
		{
			return x;
		}
	}
	return -1;
}

int binary_search(int a[],int l,int r, int x)
{
	int middle;
	int left;
	int right;
	left = l;
	right = r;
	// middle = (left + right)/2;
	// has bug when a[middle] == x first time
	// so put this in the while
	while(l < r)
	{
		middle = (left + right)/2;
		if (x > a[middle])
		{
			left = middle;
		}
		else if(x <a[middle])
		{
			right = middle;
		}
		else
		{
			return x;
		}
		middle = (left + right)/2;
	}
	return -1;
}
int binary_search_recurs(int a[],int l,int r, int x)
{
	if (r > l)
	{
		int middle = (r+l)/2;
		if (a[middle] >x)
		{
			binary_search_recurs(a,l,middle,x);
		}
		else if(a[middle] < x)
		{
			binary_search_recurs(a,middle,r,x);
		}
		else
			return x;
	}
}
int main(int argc, char const *argv[])
{
	int a[] = {1,2,3,4,5,6,7,8};
	int n = sizeof(a)/sizeof(a[0]); 
	int x = 4;
	int res;
	res = binary_search_recurs(a,0,n-1,x);
	printf("binary_search_recurs res %d\n", res);
	res = binary_search(a,0,n-1,x);
	printf("binary_search res %d\n", res);
	return 0;
}