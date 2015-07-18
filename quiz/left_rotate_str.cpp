/* 
* @Author: root
* @Date:   2015-07-03 07:34:21
* @Last Modified by:   root
* @Last Modified time: 2015-07-03 08:12:31
 left rotate string n bit
*/
#include <iostream>
#include <string.h>

using namespace std;

char * LeftRotateStr(char *str,int n)
{
	if (NULL == str || n <0)
	{
		cout<<"invalid para"<<endl;
		return NULL;
	}
	if (0 == n)
	{
		return str;
	}
	if (n >strlen(str))
	{
		cout<<"n to large"<<endl;
		return NULL;
	}
	char tmp[n];
	int len = strlen(str);
	strncpy(tmp,str,n);
	strncpy(str,str+n,len -n);
	strncpy(str+len-n,tmp,n);
}
void Reverse(char *str,int len)
{
	char *p =str;
	char *ptr = str +len-1;
	while(str <= ptr)
	{
		char tmp;
		tmp = *ptr;
		*ptr = *str;
		*str = tmp;
		ptr--;
		str++;
	}
	*(p+len) ='\0';
}
// dont use strlib
char * LeftRotateStr2(char *str,int n)
{
	if (NULL == str || n <0)
	{
		cout<<"invalid para"<<endl;
		return NULL;
	}
	if (0 == n)
	{
		return str;
	}
	if (n >strlen(str))
	{
		cout<<"n to large"<<endl;
		return NULL;
	}
	int len = strlen(str);
	Reverse(str,len);
	Reverse(str,len-n);
	Reverse(str+len-n,n);

	return str;
}
int main(){

	char str[] ="abcdefg";
	LeftRotateStr(str,2);
	cout<<str<<endl;
	cout<<"second method-----"<<endl;
	char str2[] ="abcdefg";
	LeftRotateStr2(str2,2);
	cout<<str2<<endl;
    return 0;
}