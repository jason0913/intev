<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 折半查找和插入查找对比
#define SIZE 100
int bisearch(int arr[],int n,int e)
{
	int mid,low,high;
	low = 0;
	int search_count = 0;
	high = n;
	while(low <= high)
	{
		mid = (low + high) / 2;
		search_count++;
		if (arr[mid] == e)
		{
			printf("find ! use binary search_count = %d\n",search_count);
			return e;
		} 
		else if(arr[mid] > e)
		{
			high = mid;
		}
		else
			low = mid;		
	}
	printf("not find,search_count = %d\n",search_count);
	return 0;
}

int insert_search(int arr[],int n,int e)
{
	int mid,low,high;
	low = 0;
	int search_count = 0;
	high = n;
	while(low <= high)
	{
		mid = low + (e - arr[low]) *(high - low)/(arr[high] - arr[low]);
		search_count++;
		//printf("arr[mid] = %d,e = %d\n",arr[mid],e);
		if (arr[mid] == e)
		{
			printf("find ! use insert_search_count = %d\n",search_count);
			return e;
		} 
		else if(arr[mid] > e)
		{
			high = mid;
		}
		else
			low = mid;		
	}
	printf("not find,insert_search_count = %d\n",search_count);
	return 0;
}

int main(int argc, char* argv[]) 
{
	int arr[SIZE];
	int value;
	int i = 0;
	srand((int)time(0)); 
	
	for ( i= 0; i < SIZE; i++) 
	{	
		//j= rand()%(SIZE+1); 
		arr[i] = 2*i;
	}
	printf("Initial arr:\n");
	for ( i= 0; i < SIZE; i++) 
	{
		printf("%d ",arr[i]);
	}
	printf("\ninput number to search\n");
	scanf("%d",&value);
	printf("\nsearch in arr...\n");
	bisearch(arr,SIZE,value);
	insert_search(arr,SIZE,value);
	return 0;
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 折半查找和插入查找对比
#define SIZE 100
int bisearch(int arr[],int n,int e)
{
	int mid,low,high;
	low = 0;
	int search_count = 0;
	high = n;
	while(low <= high)
	{
		mid = (low + high) / 2;
		search_count++;
		if (arr[mid] == e)
		{
			printf("find ! use binary search_count = %d\n",search_count);
			return e;
		} 
		else if(arr[mid] > e)
		{
			high = mid;
		}
		else
			low = mid;		
	}
	printf("not find,search_count = %d\n",search_count);
	return 0;
}

int insert_search(int arr[],int n,int e)
{
	int mid,low,high;
	low = 0;
	int search_count = 0;
	high = n;
	while(low <= high)
	{
		mid = low + (e - arr[low]) *(high - low)/(arr[high] - arr[low]);
		search_count++;
		//printf("arr[mid] = %d,e = %d\n",arr[mid],e);
		if (arr[mid] == e)
		{
			printf("find ! use insert_search_count = %d\n",search_count);
			return e;
		} 
		else if(arr[mid] > e)
		{
			high = mid;
		}
		else
			low = mid;		
	}
	printf("not find,insert_search_count = %d\n",search_count);
	return 0;
}

int main(int argc, char* argv[]) 
{
	int arr[SIZE];
	int value;
	int i = 0;
	srand((int)time(0)); 
	
	for ( i= 0; i < SIZE; i++) 
	{	
		//j= rand()%(SIZE+1); 
		arr[i] = 2*i;
	}
	printf("Initial arr:\n");
	for ( i= 0; i < SIZE; i++) 
	{
		printf("%d ",arr[i]);
	}
	printf("\ninput number to search\n");
	scanf("%d",&value);
	printf("\nsearch in arr...\n");
	bisearch(arr,SIZE,value);
	insert_search(arr,SIZE,value);
	return 0;
>>>>>>> 24dcaf1987354c8e05bb41117ee531c8d0335611
}