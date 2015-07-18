/* 
* @Author: root
* @Date:   2015-07-12 11:08:00
* @Last Modified by:   root
* @Last Modified time: 2015-07-12 11:13:27
*/

#include <iostream>

using namespace std;

int SecondMax(int array[],int length)
{
	if (NULL == array || length <=0)
	{
		return -1;
	}
	int max = array[0];
	int secondmax = - 2^16;
	int i;
	for (i = 1; i < length; ++i)
	{
		if (array[i] > max)
		{
			secondmax = max;
			max = array[i];
		}
		else
		{
			if (array[i] > secondmax)
			{
				secondmax = array[i];
			}
		}
	}
	return secondmax;
}
int main(){

	int array[]={2,3,4,1,5};
	int length = sizeof(array)/sizeof(array[0]);
	int secondmax = SecondMax(array,length);
	cout<<"secondmax:" <<secondmax<<endl;
    return 0;
}