#include <stdio.h>
#pragma comment(linker,"/SECTION:.rdata,RW")
int main()
{
	char *p = "hello";
	char * cp;
	cp = p;
	*(cp + 3) = 'k';
	printf("%s\n",p);
	return 0;
}