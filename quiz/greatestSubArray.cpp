/*
find greatest sum of sub array
*/
#include <iostream>

using namespace std;

int GreatestSubArray(int array[],int length)
{
	if (NULL == array || length <=0)
	{
		cout <<"invalid para"<<endl;
		return 0;
	}
	int cursum = 0;
	int greastsum = 0x80000000;
	for (int i = 0; i < length; ++i)
	{
		if (cursum <0)
		{
			cursum = array[i];
		}
		else
			cursum += array[i];
		if (cursum > greastsum)
		{
			greastsum = cursum;
		}
	}
	return greastsum;
}

int main(int argc, char const *argv[])
{
	int array[] = {1,-2,3,10,-4,7};
	int length = sizeof(array)/sizeof(array[0]);

	int res;
	res =GreatestSubArray(array,length);
	cout <<res<<endl;
	return 0;
}