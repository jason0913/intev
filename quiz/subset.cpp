/* 
* @Author: jql
* @Date:   2015-08-07 09:31:16
* @Last Modified by:   jql
* @Last Modified time: 2015-08-07 10:50:10
  all the subset of set
*/

#include <iostream>
#include <math.h>

using namespace std;

void Change(bool *ptr,int len)
{
	int i =0;
	for (int i = 0; i < len; ++i)
	{
		if (0 != *ptr)
		{
			*ptr = 0;
		}
		else
		{
			*ptr =1;
			break;
		}
		ptr++;
	}
}

int main(){

	char set[] ={'1','2','3','4'};
	int size = sizeof(set)/sizeof(set[0]);
	bool boolset[] ={0,0,0,0};

	int pw = pow(2,size);
	for (int i = 0; i < pw; ++i)
	{
		cout<<'{';
		for (int j = 0; j < size; ++j)
		{
			if (boolset[j])
			{
				cout<<set[j];
			}
		}
		cout<<'}';
		cout<<' ';
		Change(boolset,size);
	}
    return 0;
}