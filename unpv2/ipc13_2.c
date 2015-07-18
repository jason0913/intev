#include "unpipc.h"
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int c,fd,flag;
	char *ptr;
	off_t length;

	flag = O_RDWR|O_CREAT;
	while((c = getopt(argc,argv,"e")) != -1)
	{
		switch(c)
		{
			case 'e':
				flag |= O_EXCL;
				break;
		}
	}
	if (argc-2 != optind)
	{
		printf("Usage: shmcrreate [-e] <name> <length>\n");
	}
	length = atoi(argv[optind+1]);
	fd = shm_open(argv[optind],flag,FILE_MODE);
	if (fd <0)
	{
		perror("shm_open error");
		exit(-1);
	}
	ftruncate(fd,length);

	ptr = mmap(NULL,length,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if (MAP_FAILED == ptr)
	{
		perror("mmap failed");
		exit(-1);
	}
	return 0;
}