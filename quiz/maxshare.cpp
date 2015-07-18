/* 
* @Author: root
* @Date:   2015-07-09 22:38:55
* @Last Modified by:   root
* @Last Modified time: 2015-07-09 23:09:01
*/

#include <iostream>

using namespace std;

int TestShare(int array[],int length,int maxpartion,int sum,int groupsum,int aux[],int goal,int groupid)
{
	if (0 == goal)
	{
		groupid++;
		if (groupid == maxpartion+1)
		{
			return 1;
		}
	}
	for (int i = 0; i < length; ++i)
	{
		if (0 !=aux[i])
		{
			continue;
		}
		aux[i] = groupid;
		if (TestShare(array,length,maxpartion,sum,groupsum,aux,goal-array[i],groupid))
		{
			return 1;
		}
		aux[i] =0;
	}
}
int MaxShares(int array[],int length)
{
	if (NULL == array || length <0)
	{
		return 0;
	}
	int i,maxpartion;
	int sum =0;
	int aux[length];
	for (i = 0; i < length; ++i)
	{
		sum += array[i];
	}
	for (maxpartion = length; maxpartion >=2; maxpartion--)
	{
		if (length %maxpartion)
		{
			continue;
		}
		for (i = 0; i < length; ++i)
		{
			aux[i] =0;
		}
		if (TestShare(array,length,maxpartion,sum,sum/maxpartion,aux,sum/maxpartion,1))
		{
			return maxpartion;
		}
	}
	return 1;
}
int main(){

	int array[] ={3,2,4,3,6};
	int length = sizeof(array)/sizeof(array[0]);
	int maxpartion =0;
	maxpartion = MaxShares(array,length);
	cout<<"maxpartion:"<<maxpartion;
    return 0;
}