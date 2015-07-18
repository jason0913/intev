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
	if (2 !=argc)
	{
		printf("Usage msgrmid pathname\n");
		exit(-1);
	}
	mqid = msgget(ftok(argv[1],0),0);
	msgctl(mqid,IPC_RMID,NULL);
	return 0;
}