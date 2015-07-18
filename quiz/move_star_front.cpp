/* 
* @Author: root
* @Date:   2015-07-16 23:34:59
* @Last Modified by:   root
* @Last Modified time: 2015-07-17 04:51:49
  move the star in string to the front, eg: ab**cd*e12  -> ****abcde12
*/

#include <iostream>

using namespace std;

void Swap(char *ch1,char *ch2)
{
	char tmp;
	tmp = *ch1;
	*ch1 = *ch2;
	*ch2 = tmp;
}
void MoveStarFront(char array[],int length)
{
	if (NULL == array || length <=0)
	{
		return;
	}
	char *starptr = array +length -1;
	char *chptr;
	while(starptr > array)
	{
		while(('*' != *starptr) && ( starptr > array))
		{
			starptr--;
		}
		chptr = starptr;
		while(('*' == *chptr) && ( chptr > array))
		{
			chptr--;
		}
		Swap(chptr,starptr);
		if (array ==chptr)
		{
			break;
		}
	}
}
int main(){

	char array[] ="ab**cd**e*12";
	int length = sizeof(array)/sizeof(array[0]);
	MoveStarFront(array,length);
	int i;
	for (i = 0; i < length; ++i)
	{
		cout<<array[i];
	}
    return 0;
}