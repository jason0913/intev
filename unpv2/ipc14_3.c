#include "unpipc.h"
#include <sys/shm.h>

int main(int argc, char const *argv[])
{
	int i,id;
	struct shmid_ds buff;
	unsigned char *ptr;

	if (2 != argc)
	{
		printf("Usage: shmwrite pathname\n");
		exit(-1);
	}
	id = shmget(ftok(argv[1],0),0,SVSHM_MODE);
	ptr = shmat(id,NULL,0);
	shmctl(id,IPC_STAT,&buff);

	for (i = 0; i < buff.shm_segsz; i++)
	{
		*ptr++ =i%256;
		printf("%d ", i);
	}
	return 0;
}