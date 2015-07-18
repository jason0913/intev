/* 
* @Author: root
* @Date:   2015-07-10 08:55:15
* @Last Modified by:   root
* @Last Modified time: 2015-07-10 09:05:13
  find the unquine unmber in array,the is number double
*/

#include <iostream>

using namespace std;

int UniqueNum(int array[],int length)
{
	if (NULL == array || length <=0)
	{
		return -1;
	}
	int i;
	int res =array[0];
	for (int i = 1; i < length; ++i)
	{
		res ^= array[i];
	}
	return res;

}
int main(){

	int array[] = {-6,2,3,2,3};
	int length = sizeof(array)/sizeof(array[0]);
	int res;
	res = UniqueNum(array,length);
	cout<<"res:"<<res<<endl;
    return 0;
}