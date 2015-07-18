#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double MinDifference(double arr[],int n)
{
	int i,j;
	double tmp;
	if (n < 2)
	{
		return 0;
	}
	double mindiff = abs(arr[0] -arr[1]);
	for (i = 0; i < n; ++i)
	{
		for (j = i+1; j < n; ++j)
		{
			tmp = abs(arr[i] -arr[j]);
			if (tmp < mindiff)
			{
				mindiff = tmp;
			}
		}
	}
	return mindiff;
}

int main(int argc, char const *argv[])
{
	double arr[] ={1,4,5,8,12};
	double mindiff =0.0;
	unsigned int len;
	len = sizeof(arr)/sizeof(arr[0]);
	mindiff = MinDifference(arr,len);
	printf("mindiff %f\n", mindiff);
	return 0;
}