#include "unpipc.h"
#include <fcntl.h>

#define SEQFILE "seqno"

void my_lock(int),my_unlock(int);

int main(int argc, char const *argv[])
{
	int fd,i;
	long seqno;
	pid_t pid;
	ssize_t n;
	char line[MAXLINE];

	pid = getpid();
	fd = open(SEQFILE,O_RDWR|O_CREAT,0666);
	if (fd <0)
	{
		perror("open file error");
		exit(-1);
	}

	for (int i = 0; i < 20; ++i)
	{
		my_lock(fd);

		lseek(fd,0,SEEK_SET);
		n = read(fd,line,MAXLINE);
		line[n] = '\0';
		sscanf(line,"%ld",&seqno);
		printf("%s:pid = %ld,seq# = %ld\n", argv[0],(long)pid,seqno);
		seqno++;
		snprintf(line,sizeof(line),"%ld",seqno);
		lseek(fd,0,SEEK_SET);
		write(fd,line,strlen(line));
	}
	return 0;
}

void my_lock(int fd)
{
	struct flock lock;

	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;

	fcntl(fd,F_SETLK,&lock);
	return;
}
void my_unlock(int fd)
{
	struct flock lock;

	lock.l_type = F_UNLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;

	fcntl(fd,F_SETLK,&lock);
	return;
}