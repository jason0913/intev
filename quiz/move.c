#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int i,j,k,counter;
	counter = 0;
	for( i = 0; i < 100 ; i++)
	{
			for( j = 0 ; j < 50; j ++)
			{
				for	(k = 0 ;k < 20 ; k++)
				{
					if (i + 2*j + 5*k == 100)
					{
							counter++;
					printf(" i = %d, j = %d ,k = %d \n",i,j,k);
					}
				}
			}
	}
	printf("counter = %d \n",counter);
	exit(0);
}
