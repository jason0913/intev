#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "unpipc.h"

int main(int argc, char const *argv[])
{
	if (2 != argc)
	{
		perror("usage: shmunlink <name>");
		exit(-1);
	}
	shm_unlink(argv[1]);
	return 0;
}