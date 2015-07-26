/* 
* @Author: root
* @Date:   2015-07-19 02:39:09
* @Last Modified by:   root
* @Last Modified time: 2015-07-19 02:43:19
*/

#include <iostream>

using namespace std;

void ReversePair(int array[],int length)
{
	if (NULL == array || length <=0)
	{
		return;
	}
	int i,j;
	for (i = 0; i < length-1; ++i)
	{
		for (j = i+1; j < length; ++j)
		{
			if (array[i] > array[j])
			{
				cout<<"<"<<array[i]<<","<<array[j]<<"> ";
			}
		}
	}
}
int main(){

	int array[] ={176,178,180,170,171};
	int length = sizeof(array)/sizeof(array[0]);
	ReversePair(array,length);
    return 0;
}