#include "stdio.h"
#include "stdlib.h"

int main(int argc, char const *argv[])
{
	char *cp;
	const char *ccp;
	// the following is correct
	// ccp = cp;
	cp = ccp;
	return 0;
}