#include "unpipc.h"
#include <sys/shm.h>

int main(int argc, char *argv[])
{
	int c,flags,id;
	char *ptr;
	size_t length;

	flags = SVSHM_MODE |IPC_CREAT;
	while((c= getopt(argc,argv,"e")) != -1)
	{
		switch(c)
		{
			case 'e':
			flags |= IPC_EXCL;
			break;
		}
	}
	if (argc -2 != optind)
	{
		printf("Usage: shmget [-e] pathname length\n");
		exit(-1);
	}
	length = atoi(argv[optind+1]);
	id = shmget(ftok(argv[optind],0),length,flags);
	ptr = shmat(id,NULL,0);

	return 0;
}