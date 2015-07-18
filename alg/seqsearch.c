#include "alg.h"

#define Keytype int

int SeqSearch(Keytype arr[],int len,Keytype key)
{
	int i;
	// can not count len,in this ,becase parameter trun array into ptr
	/*int len;
	len = sizeof(arr)/sizeof(arr[0]);*/
	for (i = 0; i < len; ++i)
	{
		if (arr[i] == key)
		{
			return i;
		}
	}
	return 0;
}

int BinSearch(Keytype arr[],int len,Keytype key)
{
	int low,high,mid;
	low = 0;
	high = len -1;
	while(low <= high)
	{
		mid = (low +high)/2;
		if (key == arr[mid])
		{
			return mid;
		}
		else if (key > arr[mid])
		{
			low = mid;
		}
		else
			high = mid;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int arr[] = {1,2,3,4,5,7,9};
	int res;
	int len;
	len = sizeof(arr)/sizeof(arr[0]);
	res = SeqSearch(arr,len,5);
	printf("-----SeqSearch----\n");
	if (0 == res)
	{
		printf("Not find\n");
	}
	else
		printf("Find, location:%d\n", res+1);
	printf("-----BinSearch-----\n");
	res = BinSearch(arr,len,3);
	if (0 == res)
	{
		printf("Not find\n");
	}
	else
		printf("Find, location:%d\n", res+1);
	return 0;
}