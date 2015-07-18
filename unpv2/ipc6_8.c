#include "unpipc.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <sys/ipc.h>

#define MAXMSG (8192 +sizeof(long))

int main(int argc, char const *argv[])
{
	int mqid;
	ssize_t n;
	struct msgbuf *buff;

	if (2 !=argc)
	{
		printf("Usage msgrcvid mqid\n");
		exit(-1);
	}
	mqid = atoi(argv[1]);
	buff = (struct msgbuf*)malloc(MAXMSG);

	n = msgrcv(mqid,buff,MAXMSG,0,0);
	printf("read %d bytes,type = %d\n", n,buff->mtype);

	exit(0);
}