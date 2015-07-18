#include "unpipc.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

struct mq_attr attr;

int main(int argc, char *argv[])
{
	int c,flag;
	mqd_t mqd;

	flag = O_RDWR|O_CREAT;
	while((c= getopt(argc,argv,"em:z:")) != -1)
	{
		switch(c)
		{
			case 'e':
				flag |= O_EXCL;
				break;
			case 'm':
				attr.mq_maxmsg = atol(optarg);
				break;
			case 'z':
				attr.mq_msgsize =atol(optarg);
				break;
		}
	}
	if (argc-1 != optind)
	{
		printf("usage:mqcreat [-e] [-m maxmsg -z msgsize] name\n");
		exit(-1);
	}
	if ((attr.mq_maxmsg !=0 && attr.mq_msgsize ==0)||
		(attr.mq_maxmsg ==0 && attr.mq_msgsize !=0))
	{
		printf("must specify -m maxmsg -z mq_msgsize\n");
	}

	mqd = mq_open(argv[optind],flag,FILE_MODE,(attr.mq_maxmsg!=0)? &attr:NULL);
	if (mqd <0)
	{
		printf("mq_open error\n");
		exit(-1);
	}
	mq_close(mqd);
	return 0;
}