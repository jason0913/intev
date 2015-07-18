#include <sys/sem.h>
#include "unpipc.h"

int main(int argc, char const *argv[])
{
	int semid,nsems,i;
	struct semid_ds seminfo;
	unsigned short *ptr;
	union semun arg;

	if (2 != argc)
	{
		printf("Usage : semgetvalues pathname\n");
		exit(-1);
	}
	semid = semget(ftok(argv[1],0),0,0);
	if (semid <0)
	{
		perror("semget error");
		exit(-1);
	}
	arg.buf = &seminfo;
	semctl(semid,0,IPC_STAT,arg);
	nsems = arg.buf->sem_nsems;

	ptr = calloc(nsems,sizeof(unsigned short));
	arg.array = ptr;

	semctl(semid,0,GETALL,arg);
	for (i = 0; i < nsems; ++i)
	{
		printf("semval[%d] = %d\n", i,ptr[i]);
	}
	return 0;
}