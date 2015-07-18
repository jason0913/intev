/*
sort the ages,O(n)

*/

#include <stdio.h>
#include <stdlib.h>

void SortAges(int ages[],int len)
{
	if (NULL == ages || len <=0)
	{
		return;
	}
	int i,j,age;
	int index =0;
	const int oldest = 99;
	int timesofage[oldest +1];

	for ( i = 0; i <= oldest; ++i)
	{
		timesofage[i] = 0;
	}
	for ( i = 0; i < len; ++i)
	{
		 age = ages[i];
		if (age <0 || age >99)
		{
			printf("age out of range\n");
			exit(-1);
		}
		++timesofage[age];
	}
	printf("-------\n");
	for ( i = 0; i <= oldest; ++i)
	{
		printf("timesofage[%d] =%d\n", i,timesofage[i]);
	}
	for ( i = 0; i < oldest; ++i)
	{
		for ( j = 0; j < timesofage[i]; ++j)
		{
			ages[index] =i;
			printf("%d ", ages[i]);
			++index;
		}
	}
	printf("index = %d\n", index);

}

int main(int argc, char const *argv[])
{
	int i;
	int ages[] = {70,20,60,50,40,40};
	int len = sizeof(ages)/sizeof(ages[0]);
	SortAges(ages,len);
	for (i = 0; i < len; ++i)
	{
		printf("%d ", ages[i]);
	}
	return 0;
}