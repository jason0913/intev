#include "stdio.h"

// count the num of 1 in binary num
int count_bit(unsigned int n)
{
	int count =0;
	int rem =0;
	while(0 != n)
	{
		if (1 ==(rem= n%2))
		{
			count++;
		}
		n = n/2;
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