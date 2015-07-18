#include "alg.h"

int main(int argc, char const *argv[])
{
	int MB =1024;
	while(1)
	{
		malloc(MB);
		printf("Allocated %d B\n", MB);
		sleep(1);
		MB=MB*2;
	}
	return 0;
}