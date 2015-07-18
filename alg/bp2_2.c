#include "stdio.h"

// count the num of 1 in binary num
int count_bit(unsigned int n)
{
	printf("in count_bit func\n");
	int count =0;
	while(0 != n)
	{
		if (n & 0x1)
		{
			count++;
		}
		n =n >>1;
	}
	return count;
}

int main(int argc, char const *argv[])
{
	unsigned int num;
	printf("Input a num\n");
	scanf("%d",&num);
	printf("1 count in %d is %d\n", num,count_bit(num));
	return 0;
}