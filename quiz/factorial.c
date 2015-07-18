#include <stdio.h>

int main()
{
	int j;
	int i = 0xFE78DA45;
	int k = 0xAC3189B2;
	int res =1;
	for(j = 0; j < k; j++)
	{
		res *= i;
	}
	printf("res = %x",res);
	return 0;
}