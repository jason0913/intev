/* 
* @Author: root
* @Date:   2015-07-05 05:03:27
* @Last Modified by:   root
* @Last Modified time: 2015-07-05 05:34:19
  is continous in five numbers,0 stand for any value
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

int compare(const void *arg1,const void *arg2)
{
	return *(int *)arg1 -*(int *)arg2;
}

bool IsContinue(int *numbers,int lenght)
{
	if (NULL == numbers || lenght <1)
	{
		return false;
	}
	qsort(numbers,lenght,sizeof(int),compare);
	int count_zero =0;
	int count_gap =0;
	int i;
	for (i = 0; i < lenght; ++i)
	{
		if (0 == numbers[i])
		{
			count_zero++;
		}
	}
	// count the gap in array
	for (i = 0; i < lenght-1; ++i)
	{
		if (numbers[i] == numbers[i+1])
		{
			if (numbers[i] != 0)
			{
				return false;
			}
		}
		if (numbers[i] +1 != numbers[i+1])
		{
			if ((numbers[i+1] !=0))
			{
				count_gap++;
			}
		}
	}
	// gap is more than zero ,can not continue
	if (count_gap > count_zero)
	{
		return false;
	}
	else
		return true;

}
int main(){

	// 0 0 can trun into 2 ,3 so continue
	int numbers[] ={1,0,4,0,5};
	int lenght = sizeof(numbers)/sizeof(numbers[0]);
	bool res;
	res = IsContinue(numbers,lenght);
	cout<<"continue?:"<<res<<endl;

    return 0;
}