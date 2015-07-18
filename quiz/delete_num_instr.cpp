/* 
* @Author: root
* @Date:   2015-07-17 05:03:51
* @Last Modified by:   root
* @Last Modified time: 2015-07-17 11:42:34
  delete number in string
*/

#include <iostream>

using namespace std;

void DeleteNumInStr(char array[],int length)
{
	if (NULL == array || length <=0)
	{
		return;
	}
	char *chptr = array;
	char *numptr;
	int movelen =0;
	while('\0' != *chptr)
	{
		while(isalpha(*chptr))
			chptr++;
		numptr = chptr;
		while(isdigit(*numptr))
		{
			numptr++;
			movelen++;
		}
		char *moveptr =numptr;
		int i;
		for (int i = 0; i < movelen; ++i)
		{
			while('\0' != *moveptr)
			{
				*(moveptr-1) = *moveptr;
				moveptr++;
			}
		}
		*(moveptr-1) = '\0';
	}
	*chptr ='\0';
}
int main(){

	char array[] ="ab12de34fg";
	int length = sizeof(array)/sizeof(array[0]);
	DeleteNumInStr(array,length);
	int i;
	for (i = 0; i < length; ++i)
	{
		cout<<array[i];
	}
    return 0;
}