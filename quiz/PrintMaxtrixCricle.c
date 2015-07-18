#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int matrix[4][4];
	int i,j;
	int value =1;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			matrix[i][j] = value;
			value++;
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	printf("--------\n");
	for (int i = 0; i < 4; ++i)
	{
		printf("%d ", matrix[0][i]);
	}
	for (int i = 1; i < 4; ++i)
	{
		printf("%d ", matrix[i][3]);
	}
	for (int i = 3; i>0; --i)
	{
		printf("%d ", matrix[3][i]);
	}
	for (int i = 3; i >0; --i)
	{
		printf("%d ", matrix[i][0]);
	}
	return 0;
}