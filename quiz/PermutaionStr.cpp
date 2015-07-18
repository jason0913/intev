/* 
* @Author: root
* @Date:   2015-07-10 03:27:22
* @Last Modified by:   root
* @Last Modified time: 2015-07-10 03:48:11
  a,b,c three char all permution
*/

#include <iostream>

using namespace std;

void Swap(char *a,char *b)
{
	char tmp;
	*a = tmp;
	*a = *b;
	*b = tmp;
}

void PermutionStr(char *pstr,char *pbegin)
{
	if ('\0' == *pbegin)
	{
		cout<<pstr<<endl;
	}
	else
	{
		for (char *p = pbegin; *p != '\0'; ++p)
		{
			// Swap(pstr,p);
			char tmp = *p;
			*p = *pstr;
			*pstr = tmp;
			PermutionStr(pstr,pbegin+1);
			// Swap(pstr,p);
			tmp = *p;
			*p = *pstr;
			*pstr = tmp;
		}
	}
}
void Permution(char *pstr)
{
	if (NULL == pstr)
	{
		return;
	}
	PermutionStr(pstr,pstr);
}

int main(){

	char pstr[] ="abc";
	Permution(pstr);
    return 0;
}