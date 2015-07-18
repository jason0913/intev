#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *p = "hello";
	// reverse(p);
	printf("%s\n",p);
	char arr[10];
	char *pr = arr;
	char c;
	int i ;
	int  *pi;
	printf("sizeof(char arr) = %d\n",sizeof(arr));
	printf("sizeof(char *p) = %d\n",sizeof(pr));
	printf("sizeof(char c) = %d\n",sizeof(c));
	printf("sizeof(int i ) = %d\n",sizeof(i));
	printf("sizeof(int *pi ) = %d\n",sizeof(pi));
	return 0;
}