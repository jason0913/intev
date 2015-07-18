#include <stdio.h>
#include <stdlib.h>

char *p = "hello world";
char arr[100];

void * memcpy2(size_t count)
{
	int i;
	char *cp = arr;
	printf("before:\n");
	printf("p = %x\n",p);
	printf("cp = %x\n",cp);	
	if(p == NULL || cp == NULL || count < 0)
		return NULL;

	for(i = 0 ; i < count ; i++)
	{
		*cp++ = *p++;
	}
	*cp = '\0';
	printf("after:\n");
	printf("p = %x\n",p);
	printf("cp = %x\n",cp);
	return p;
}

int main()
{
	
	printf("p = %x\n",p);
	printf("arr = %x\n",arr);
	memcpy2(20);
	printf("p = %x\n",p);
	printf("%s",arr);
	return 0;
}