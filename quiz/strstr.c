#include <stdio.h>

/* char *funcstrstr(char *str1,const char *str2)
{
	if(strlen(str2) > strlen(str1))
		return NULL;
	while(*str1 != '\0' || *str2 != '\0')
	{
		if(*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else
			str1++;
	}
} */
int main()
{
	char *p = "abcd";
	char *cp = "bcd";
	char s[] = "Welcometohengtian";
	char *res = strstr(p,cp);
	printf("%s ",res);
	printf("%s %d",s+7,sizeof(s));
	return 0;
}