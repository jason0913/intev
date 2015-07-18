#include "alg.h"

#define DUMBCOPY for (i = 0; i < 65536; ++i)\
dest[i] = sour[i]

#define SAMRTCOPY memcpy(dest,sour,65536)

int main(int argc, char const *argv[])
{
	char dest[65536],sour[65536];
	int i,j;
	for (i = 0; i < 100; ++i)
	{
		// change below to DUMBCOPY,then compare time
		SAMRTCOPY;
		// DUMBCOPY;
	}
	return 0;
}