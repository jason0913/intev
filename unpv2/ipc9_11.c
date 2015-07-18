#include "unpipc.h"
#include <fcntl.h>

/*
only runing one instance of a programming
*/

#define PATH_PIDFILE "pidfile"
#define write_lock(fd,offset,whence,len) \
	lock_reg(fd,F_SETLK,F_WRLCK,offset,whence,len)

int lock_reg(int fd,int cmd,int type,off_t offset,int whence,off_t len)
{
	struct flock lock;
	lock.l_type = type;
	lock.l_start = offset;
	lock.l_whence = whence;
	lock.l_len = len;

	return((fcntl(fd,cmd,&lock)));
}
int main(int argc, char const *argv[])
{
	int pidfd;
	char line[MAXLINE];

	pidfd = open(PATH_PIDFILE,O_RDWR|O_CREAT,0666);
	if (pidfd <0)
	{
		perror("open PATH_PIDFILE error");
		exit(1);
	}
	if (write_lock(pidfd,0,SEEK_SET,0) <0)
	{
		if (EACCES == errno || EAGAIN == errno)
		{
			printf("unable to lock file %s,is process %s running\n",
				PATH_PIDFILE,argv[0]);
			exit(0);
		}
		else
			printf("unable to lock %s\n", PATH_PIDFILE);
	}
	snprintf(line,sizeof(line),"%ld\n",(long)getpid());
	;
	write(pidfd,line,strlen(line));
	while(1)
	{
		printf("process %d running\n", getpid());
		sleep(2);
	}
	return 0;
}