#include "unpipc.h"
#include <sys/sem.h>
int main(int argc, char const *argv[])
{
	int semid;
	if (2 != argc)
	{
		printf("Usage:semrmid pathname\n");
		exit(-1);
	}
	semid = semget(ftok(argv[1],0),0,0);
	semctl(semid,0,IPC_RMID);
	return 0;
}
