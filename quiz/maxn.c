#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintMaxN(int n)
{
	int max = 1;
	int i;
	if (n <0)
	{
		printf("Not postive n\n");
		exit(-1);
	}
	for (i = 0; i < n; ++i)
	{
		max *= 10;
	}
	for (i = 0; i < max; ++i)
	{
		printf("%d ", i);
	}
}
void PrintNumber(char *number)
{
	int beginning0 = 1;
	int Length = strlen(number);
	int i;
	for (int i = 0; i < Length; ++i)
	{
		if ('0' !=number[i] && beginning0)
		{
			beginning0 = 0;
		}
		if (0 ==beginning0)
		{
			printf("%c", number[i]);
		}
	}
}
int Increment(char *number)
{

}
void PrintMaxN2(int n)
{
	int max = 1;
	int i;
	if (n <0)
	{
		printf("Not postive n\n");
		exit(-1);
	}
	char *number = (char *)malloc(sizeof(n+1));
	memset(number,'0',n);
	number[n] = '\0';

	while(!Increment(number))
	{
		PrintNumber(number);
	}
	free(number);
}
int main(int argc, char const *argv[])
{
	int n;
	printf("Input n\n");
	scanf("%d",&n);
	// PrintMaxN(n);
	PrintNumber("0009080");
	printf("\n");
	return 0;
}