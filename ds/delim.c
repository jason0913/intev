#include "ds.h"


char* delim(char *s,char ch)
{
	char *res = (char*)malloc(100*sizeof(char));
	char *head = res;
	while('\0' != *s)
	{
		if (ch == *s)
		{
			*(res+1) = '\0';
			return head;	
		}
		*res = *s;
		s++;
		res++;
	}
}

int main(int argc, char const *argv[])
{
	char *str = "abc.123";
	char *ptr = NULL;
	printf("before str %s\n",str);
	ptr = delim(&str,'.');
	printf("%s\n", ptr);
	//str++;
	printf("after str %s\n",str);
	return 0;
}