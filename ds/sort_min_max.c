#include "ds.h"

void sort(int a[],int size)
{
	int i,j;
	int tmp;
	for (i = 1; i < size; ++i)
	{
		for (j = 0; j < i; ++j)
		{
			if (a[j] > a[i])
			{
				tmp = a[j];
				a[j] = a[i];
				a[i] =tmp;
			}
		}
	}
}
/*
int arr_len(int a[])
{
	return sizeof(a)/sizeof(int);
}*/
int arr_len(int a[])
{
	int i=0;
	while('\0' != a[i])
	{
		i++;
	}
	return i;
}

void print_arr(int a[],int size)
{
	int i=0;
	while(i < size)
	{
		printf("%d ", a[i]);
		i++;
	}
}
int main(int argc, char const *argv[])
{
	char input[128];
	char *result;
	int arr_int[128];
	int index = 0;
	fgets(input,sizeof(input),stdin);
	result = strtok(input,",");
	while(NULL != result)
	{
		printf("%s ",result);
		arr_int[index] = atoi(result);
		index++;
		result = strtok(NULL,",");
	}
	printf("\nbefore:\n");
	print_arr(arr_int,index);
	printf("\nafter:\n");
	sort(arr_int,index);
	print_arr(arr_int,index);
	return 0;
}