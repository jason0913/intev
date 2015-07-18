#include "unpipc.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <sys/ipc.h>

int main(int argc, char const *argv[])
{
	int mqid;
	size_t len;
	long type;
	struct msgbuf *ptr;

	if (4 != argc)
	{
		printf("Usage:msgsnd pathname bytes type\n");
		exit(-1);
	}
	len =atoi(argv[2]);
	type = atoi(argv[3]);
	mqid = msgget(ftok(argv[1],0),MSG_W);
	if (mqid <0)
	{
		perror("msgget error");
		exit(-1);
	}
	ptr = (struct msgbuf*)calloc(sizeof(long) +len,sizeof(char));
	ptr->mtype = type;

	msgsnd(mqid,ptr,len,0);
	return 0;
}