/*
reverse pairs in array
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int InversePairs(int data[],int length)
{
	if (NULL == data || length <0)
	{
		printf("invalid para\n");
		return 0;
	}
	int i,j;
	for (i = 0; i < length-1; ++i)
	{
		for (j = i+1; j < length; ++j)
		{
			if (data[i] > data[j])
			{
				printf("(%d,%d)\n", data[i],data[j]);
			}
		}
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	int data[] ={7,5,6,4};
	int length = sizeof(data)/sizeof(data[0]);
	InversePairs(data,length);
	return 0;
}