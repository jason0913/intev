#include <stdio.h>

int g1=0,g2=0,g3=0;

int main(int argc, char const *argv[])
{
	static int s1=0,s2=0,s3=0;
	int v1=0,v2=0,v3=0;

	printf("0x%08x\n", &v1);
	printf("0x%08x\n", &v2);
	printf("0x%08x\n", &v3);
	printf("---------\n");
	printf("0x%08x\n", &g1);
	printf("0x%08x\n", &g2);
	printf("0x%08x\n", &g3);
	printf("---------\n");
	printf("0x%08x\n", &s1);
	printf("0x%08x\n", &s2);
	printf("0x%08x\n", &s3);
	return 0;
}