#include "unpipc.h"
#include <sys/shm.h>

int main(int argc, char const *argv[])
{
	int id;
	if (2 != argc)
	{
		printf("Usage: shrmid pathname\n");
		exit(-1);
	}
	id = shmget(ftok(argv[1],0),0,SVSHM_MODE);
	shmctl(id,IPC_RMID,NULL);

	return 0;
}