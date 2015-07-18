#include "unpipc.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

int main(int argc, char *argv[])
{
	int c,flag;
	mqd_t mqd;

	flag = O_RDWR|O_CREAT;
	while((c=getopt(argc,argv,"e")) != -1)
	{
		switch(c)
		{
			case 'e':
			flag |= O_EXCL;
			break;
		}
	}
	if (argc -1 != optind)
	{
		printf("Usage :mqcreate [-e] name\n");
		exit(-1);
	}
	mqd = mq_open(argv[optind],flag,FILE_MODE,NULL);
	if (mqd <0)
	{
		perror("mq_open error");
		exit(-1);
	}
	mq_close(mqd);
	return 0;
}
