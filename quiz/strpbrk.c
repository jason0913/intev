#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 依次检验字符串s1中的字符，当被检验字符在字符串s2中也包含时，则停止检验，并返回该字符位置
int main()
{
	char *s1="Welcome To Beijing";
	char *s2="BIT";
	char *p;
	p=strpbrk(s1,s2);
	if(p)
		printf("%s\n",p); /*lcome To Beijing*/
	else
		printf("Not Found!\n");
	p=strpbrk(s1, "Da");
	if(p)
		printf("%s",p);
	else
		printf("Not Found!"); /*not found*/
	return 0;
}