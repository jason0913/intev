#include "unpipc.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

int main(int argc, char *argv[])
{
	int c,flag;
	mqd_t mqd;
	ssize_t n;
	unsigned int prio;
	char *buff;
	struct mq_attr attr;

	flag = O_RDONLY;
	while((c=getopt(argc,argv,"n")) != -1)
	{
		switch(c)
		{
			case 'n':
			flag |= O_NONBLOCK;
			break;
		}
	}
	if (argc -1 != optind)
	{
		printf("Usage :mqreceive [-n] name\n");
		exit(-1);
	}
	mqd = mq_open(argv[optind],flag);
	if (mqd <0)
	{
		printf("mq_open error\n");
		exit(-1);
	}
	buff = (char*)malloc(attr.mq_msgsize);

	n = mq_receive(mqd,buff,attr.mq_msgsize,&prio);
	printf("read %ld bytes prio =%u\n", (long)n,prio);
	mq_close(mqd);
	return 0;
}