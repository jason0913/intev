#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i;
	printf("INput n\n");
	scanf("%d",&i);
	if(0 == (i &(i-1)))
	{
		printf("is 2 ^n\n");
	}
	else
		printf("not 2 ^n\n");
	return 0;
}