#include "unpipc.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

int main(int argc, char const *argv[])
{
	mqd_t mqd;
	char *ptr;
	size_t len;
	unsigned int prio;

	if (4 != argc)
	{
		printf("Usage: mssend name bytes prio\n");
		exit(-1);
	}
	len = atoi(argv[2]);
	prio = atoi(argv[3]);

	mqd = mq_open(argv[1],O_WRONLY);
	if (mqd <0)
	{
		printf("mq_open error\n");
		exit(-1);
	}
	ptr = (char*)calloc(len,sizeof(char));
	mq_send(mqd,ptr,len,prio);
	return 0;
}