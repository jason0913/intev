#include "unpipc.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <sys/ipc.h>

int main(int argc, char *argv[])
{
	int c,oflag,mqid;

	oflag = SVMSG_MODE|IPC_CREAT;
	while((c = getopt(argc,argv,"e")) != -1)
	{
		switch(c)
		{
			case 'e':
				oflag |=IPC_EXCL;
				break;
		}
	}
	if (optind != argc-1)
	{
		printf("usage: mscreat [-e] pathname\n");
		exit(-1);
	}
	mqid = msgget(ftok(argv[optind],0),oflag);
	if (mqid<0)
	{
		perror("msgget error");
		exit(-1);
	}
	return 0;
}