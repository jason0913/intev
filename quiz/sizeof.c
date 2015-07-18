#include <stdio.h>

// sizeof 判断类型的大小
int main()
{
	int *p;
	char *cp = NULL;
	int arr[10];
	p = arr;
	printf("sizeof(p) = %d\n",sizeof(p));
	printf("sizeof(cp) = %d\n",sizeof(cp));
	printf("sizeof(arr) = %d\n",sizeof(arr));
	return 0;
}