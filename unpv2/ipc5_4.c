#include "unpipc.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

int main(int argc, char const *argv[])
{
	mqd_t mqd;
	struct mq_attr attr;

	if (2 != argc)
	{
		printf("Usage:mqgetattr name\n");
		exit(-1);
	}
	mqd = mq_open(argv[1],O_RDONLY);
	if (mqd <0)
	{
		perror("mq_open error");
		exit(-1);
	}
	mq_getattr(mqd,&attr);
	printf("max #msgs= %ld,max #bytes/msg =%ld,#cur on queue=%ld\n",
	 attr.mq_maxmsg,attr.mq_msgsize,attr.mq_curmsgs);
	mq_close(mqd);
	return 0;
}