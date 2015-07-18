/* 
* @Author: root
* @Date:   2015-07-03 09:25:54
* @Last Modified by:   root
* @Last Modified time: 2015-07-03 22:02:04
  find a seq increase which sum equal a value
*/

#include <iostream>

using namespace std;

void PrintContinuousSeq(int array[],int small,int big)
{
	int i;
	for (i = small; i <= big; ++i)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

void FindContinuousSeq(int array[],int length, int sum)
{
	int small,big;
	int cursum =0;
	small =0;

	while(small <= length-2)
	{
		big = small+1;
		cursum = array[small];
		while(big <=length-1)
		{
			cursum += array[big];
			if (cursum == sum)
			{
				PrintContinuousSeq(array,small,big);
				// break;
			}
			else if (cursum < sum)
			{
				big++;
				// cursum += array[big];
			}
			else
			{
				cursum =0;
				break;
			}
		}
		small++;
	}
}
int main(){

	int array[] ={1,2,3,4,5,6,7,8,9,10,11,12};
	int length = sizeof(array)/sizeof(array[0]);
	int sum =20;
	FindContinuousSeq(array,length,sum);
    return 0;
}