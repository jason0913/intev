#include "ds.h"
#include <setjmp.h>

jmp_buf buf;

void banana()
{
	printf("in banana()\n");
	longjmp(buf,1);
	printf("you nerver see this,because longjmp\n");
}

int main(int argc, char const *argv[])
{
	if (setjmp(buf))
	{
		printf("jump back, in main()\n");
	}
	else
	{
		printf("first time through\n");
		banana();
	}
	return 0;
}