#include <iostream>

using namespace std;

bool CheckThanHalf(int numbers[],int length,int num)
{
	int times = 0;
	for (int i = 0; i < length; ++i)
	{
		if (num == numbers[i])
		{
			times++;
		}
	}
	bool isMoreHalf = true;
	if (times *2  <=length)
	{
		isMoreHalf = false;
	}
	return isMoreHalf;
}

int MoreThanHalf(int numbers[],int length)
{
	if (NULL == numbers || length <=0)
	{
		cout <<"para invalid"<<endl;
		return 0;
	}
	int i;
	int times =1;
	int result = numbers[0];
	for (int i = 1; i < length; ++i)
	{
		if (0== times)
		{
			result = numbers[i];
			times = 1;
		}
		if (result == numbers[i])
		{
			times++;
		}
		else
		{
			// result = numbers[i];
			times--;
		}
	}
	if (!CheckThanHalf(numbers,length,result))
	{
		return 0;
	}
}

int main(int argc, char const *argv[])
{
	int numbers[] = {1,2,3,2,2,2};
	int length = sizeof(numbers)/sizeof(numbers[0]);
	cout <<" MoreThanHalf:"<<MoreThanHalf(numbers,length)<<endl;
	return 0;
}