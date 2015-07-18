/* 
* @Author: root
* @Date:   2015-07-16 11:13:52
* @Last Modified by:   root
* @Last Modified time: 2015-07-17 04:57:56
*/

#include <iostream>

using namespace std;

int myatoi(char *str)
{
	int flag =1;
	char *ptr = str;
	int c = 0;
	if (NULL == ptr)
	{
		cout<<"NULL str"<<endl;
		return 0;
	}
	if ('-' == *ptr)
	{
		flag = -1;
		ptr++;
	}
	if ('+' == *ptr)
	{
		flag =1;
		ptr++;
	}
	while(('\0' != *ptr))
	{
		if (*ptr >= '0' && *ptr <= '9' )
		{
			c = 10 *c + (*ptr -'0');
		}
		ptr++;
	}
	return flag *c;

}
int main(){

	char str[] = "-012cs3";
	int num;
	num = myatoi(str);
	cout<<num<<endl;
    return 0;
}