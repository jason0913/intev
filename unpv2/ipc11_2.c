#include "unpipc.h"
#include <sys/sem.h>

int main(int argc, char **argv)
{
	int c,oflag,nsems,semid;

	oflag = SVSEM_MODE|IPC_CREAT;
	while(-1 !=(c=getopt(argc,argv,"e")))
	{
		switch(c)
		{
			case 'e':
			oflag |= IPC_EXCL;
			break;
		}
	}
	if (argc -2 != optind)
	{
		printf("Usage :semcreat [-e] pathname nsems\n");
		exit(-1);
	}
	nsems = atoi(argv[optind+1]);
	semid = semget(ftok(argv[optind],0),nsems,oflag);
	if (semid < 0)
	{
		perror("semget error");
		exit(-1);
	}
	return 0;
}