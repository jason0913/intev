#include "unpipc.h"
#include <sys/shm.h>

int main(int argc, char const *argv[])
{
	int i,id;
	struct shmid_ds buff;
	unsigned char *ptr,c;

	if (2 != argc)
	{
		printf("Usage: shmread pathname\n");
		exit(-1);
	}
	id = shmget(ftok(argv[1],0),0,SVSHM_MODE);
	ptr = shmat(id,NULL,0);
	shmctl(id,IPC_STAT,&buff);

	for (i = 0; i < buff.shm_segsz; i++)
	{
		if ((c=*ptr++) != (i%256))
		{
			printf("ptr[%d] = 5d\n", i,c);
		}
	}
	return 0;
}