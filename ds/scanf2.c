#include "ds.h"

// stdin serverl nums,delimer with comma or space
int main(int argc, char const *argv[])
{
	int arr[20];
	int j,a;
	int i=0;
	while(scanf("%d%*c",&a) != EOF)
	{
		arr[i] = a;
		i++;
	}
	for (j = 0; j < i; ++j)
	{
		printf("%d ", arr[j]);
	}
	return 0;
}