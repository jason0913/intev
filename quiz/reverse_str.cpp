/* 
* @Author: root
* @Date:   2015-07-03 04:36:07
* @Last Modified by:   root
* @Last Modified time: 2015-07-04 21:40:09
   Reverse word in a sentance
*/

#include <iostream>
#include <string.h>

using namespace std;

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
void ReverseWordInSen(char *sentance)
{
	if (NULL == sentance)
	{
		cout<<"invalid para"<<endl;
		return;
	}
	int len = strlen(sentance);
	Reverse(sentance,len);
	cout<<sentance<<endl;
	char *p = sentance;
	char *word_start = sentance;
	int word_len =0;
	while('\0' != *p)
	{
		word_start = p;
		if (' ' == *p)
		{
			Reverse(word_start -word_len,word_len);
			// p++;
			word_len =0;
		}
		p++;
		word_len++;
	}

}

int main()
{

	char str[] = "I am code";
	// int len = sizeof(str)/sizeof(str[0])-1;
	ReverseWordInSen(str);
	cout<<str<<endl;
    return 0;
}