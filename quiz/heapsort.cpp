/* 
* @Author: root
* @Date:   2015-07-17 02:20:20
* @Last Modified by:   root
* @Last Modified time: 2015-07-17 02:46:26
*/

#include <iostream>

using namespace std;

void Sift(int array[],int low,int high)
{
	int i = low,j = 2*i;
	int tmp = array[i];
	while( j <= high)
	{
		if (j < high && array[j] <array[j+1])
		{
			j++;
		}
		if (tmp < array[j])
		{
			i =j;
			j = 2*i;
		}
		else
			break;
	}
	array[i] = tmp;
}

void HeapSort(int array[],int length)
{
	if (NULL == array || length <=0)
	{
		return;
	}
	int i,tmp;
	// init heap
	for (i = length/2; i >=1; i--)
	{
		Sift(array,i,length);
	}
	for (i = length; i >= 2; ++i)
	{
		tmp = array[1];
		array[1] = array[i];
		array[i] = tmp;
		Sift(array,1,i-1);
	}
}
int main(){

	int array[] ={-1,2,4,3,5,1};
	int length = sizeof(array)/sizeof(array[0]);
	HeapSort(array+1,length-1);
	int i;
	for (i = 1; i < length; ++i)
	{
		cout<<array[i] <<" ";
	}
    return 0;
}