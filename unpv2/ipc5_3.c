#include "unpipc.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

int main(int argc, char const *argv[])
{
	if (2 != argc)
	{
		printf("Usage:mqunlink name\n");
		exit(-1);
	}
	mq_unlink(argv[1]);
	return 0;
}