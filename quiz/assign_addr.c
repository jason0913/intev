#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	long *p;
	printf("p = %x\n", p);
	p = (long *)(0x12345678);
	printf("p = %x\n", p);
	*p=1;
	printf("*p=\n", *p);
	return 0;
}