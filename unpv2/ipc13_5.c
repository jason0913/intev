#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "unpipc.h"

int main(int argc, char const *argv[])
{
	int i,fd;
	struct stat stat;
	unsigned char *ptr,c;

	if (2 != argc)
	{
		printf("Usage :shmread <name>\n");
		exit(-1);
	}
	fd = shm_open(argv[1],O_RDONLY,FILE_MODE);
	fstat(fd,&stat);

	ptr = mmap(NULL,stat.st_size,PROT_READ,MAP_SHARED,fd,0);
	if (MAP_FAILED == ptr)
	{
		perror("mmap error");
		exit(-1);
	}
	close(fd);

	for (i = 0; i < stat.st_size; ++i)
	{
		if (i %256 != (c = *ptr++))
		{
			printf("ptr[%d] = %d\n", i,c);
		}
	}
	return 0;
}