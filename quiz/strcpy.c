#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char s[] ="123456";
	char d[] = "789";
	// char d[7] = "789";
	strcpy(d,s);
	printf("d: %s,s: %s\n", d,s);
	return 0;
}