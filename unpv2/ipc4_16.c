#include "unpipc.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define FIFO1 "tmp/fifo1"
#define FIFO2 "tmp/fifo2"
// #define FILE_MODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)
void client(int ,int);
void server(int ,int);

int main(int argc, char const *argv[])
{
	int readfd,writefd;
	pid_t childpid;

	if ((mkfifo(FIFO1,FILE_MODE) <0) &&(errno != EEXIST))
	{
		perror("can not creat FIFO1 ");
		exit(-1);
	}
	if ((mkfifo(FIFO2,FILE_MODE) <0) &&(errno != EEXIST))
	{
		perror("can not creat FIFO2");
		exit(-1);
	}
	if (0 ==(childpid = fork()))
	{
		readfd = open(FIFO1,O_RDONLY,0);
		writefd = open(FIFO2,O_WRONLY,0);
		server(readfd,writefd);
		exit(0);
	}
	writefd = open(FIFO1,O_RDONLY,0);
	readfd = open(FIFO2,O_WRONLY,0);
	client(readfd,writefd);

	waitpid(childpid,NULL,0);
	close(readfd);
	close(writefd);

	unlink(FIFO1);
	unlink(FIFO2);
	return 0;
}

void server(int readfd,int writefd)
{
	int fd;
	char buf[MAXLINE];
	ssize_t n;

	if ((n = read(readfd,buf,MAXLINE))==0)
	{
		perror("read filepath error");
		return;
	}
	buf[n]='\0';
	printf("server:read path from client\n");
	if ((fd =open(buf,O_RDONLY)) <0)
	{
		snprintf(buf,sizeof(buf),"cant not open %s",strerror(errno));
		n = strlen(buf);
		write(writefd,buf,n);
	}
	else
	{
		while((n = read(fd,buf,MAXLINE)) >0)
		{
			write(writefd,buf,n);
		}
		close(fd);
	}
}
void client(int readfd,int writefd)
{
	size_t len;
	ssize_t n;
	char buf[MAXLINE];

	printf("client:input path\n");
	fgets(buf,MAXLINE,stdin);
	len = strlen(buf);
	if ('\n' == buf[len-1])
	{
		len--;
	}
	if (write(writefd,buf,len)<0)
	{
		perror("write writefd error");
		return;
	}
	printf("client:read from server:\n");
	while((n = read(readfd,buf,MAXLINE)) >0)
	{
		fputs(buf,stdout);
	}
}