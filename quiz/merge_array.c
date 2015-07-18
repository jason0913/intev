#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int arr1[100] = {2,4,6};
	int arr2[10] = {1,3,5};

	int i,j;
	int len1,len2;
	int fact_len;
	// len2 = sizeof(arr2)/sizeof(arr2[0]);
	// len1 = sizeof(arr1)/sizeof(arr1[0]);
	len1 = len2 = 3;
	fact_len = 3;
	for (i = 0; i < len2; ++i)
	{

		for (j = len1-1; j >=0; --j)
		{
			if (arr1[j] > arr2[i])
			{
				arr1[j+1] =arr1[j];
				if (0 ==j)
				{
					arr1[j] = arr2[i];
					fact_len++;
				}
			}
			else
			{
				arr1[j] = arr2[i];
				fact_len++;
				break;
			}
		}
		len1 = fact_len;
	}
	for (i = 0; i < len1; ++i)
	{
		printf("%d \n", arr1[i]);
	}
	return 0;
}