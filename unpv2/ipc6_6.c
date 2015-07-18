#include "unpipc.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <sys/ipc.h>

#define MSXMSG (8192 + sizeof(long))

int main(int argc, char *argv[])
{
	int c,flag,mqid;
	long type;
	ssize_t n;
	struct msgbuf *buff;

	type = flag =0;
	while((c = getopt(argc,argv,"nt:")) != -1)
	{
		switch(c)
		{
			case 'n':
				flag |=IPC_NOWAIT;
				break;
			case 't':
				type = atol(optarg);
				break;
		}
	}
	if (argc-1 != optind)
	{
		printf("usage:msgrcv [-n] [-t type] pahtname\n");
		exit(-1);
	}
	mqid = msgget(ftok(argv[optind],0),MSG_R);
	if (mqid <0)
	{
		printf("msgget error\n");
		exit(-1);
	}
	buff = (struct msgbuf*)malloc(MSXMSG);
	n = msgrcv(mqid,buff,MSXMSG,type,flag);
	printf("read %d types,type=%d\n", n,buff->mtype);
	return 0;
}