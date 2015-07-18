/*
min element in rotate array
*/
#include <stdio.h>
#include <stdlib.h>

int Min(int number[],int length)
{
	if (NULL == number)
	{
		printf("empty array\n");
		exit(-1);
	}
	if (length <=0)
	{
		printf("array length =0\n");
		exit(-1);
	}
	int index1 = 0;
	int index2 = length -1;
	int midindex = index1;
	while(index1 < index2)
	{
		if (1 == index2-index1)
		{
			midindex = index2;
			break;
		}
		midindex = (index1 +index2)/2;
		if (number[midindex] >= number[index1])
		{
			index1= midindex;
		}
		else if (number[midindex] <= number[index2])
		{
			index2 = midindex;
		}
	}
	return number[midindex];
}

int main(int argc, char const *argv[])
{
	int number[] = {6,7,8,3,4,5};
	// int number[] = {6,6,6,6};
	int len = sizeof(number)/sizeof(number[0]);
	int res;
	res =Min(number,len);
	printf("res =%d\n", res);
	return 0;
}