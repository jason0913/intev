#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "unpipc.h"

int main(int argc, char const *argv[])
{
	int i,fd;
	struct stat stat;
	unsigned char *ptr;

	if (2 != argc)
	{
		printf("Usage :shmwrite <name>\n");
		exit(-1);
	}
	fd = shm_open(argv[1],O_RDWR,FILE_MODE);
	fstat(fd,&stat);

	ptr = mmap(NULL,stat.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if (MAP_FAILED == ptr)
	{
		perror("mmap error");
		exit(-1);
	}
	close(fd);

	for (i = 0; i < stat.st_size; ++i)
	{
		*ptr++ = i % 256;
	}
	return 0;
}