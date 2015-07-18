#include "unpipc.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

void server(int,int);
void child(int,int);

int main(int argc, char const *argv[])
{
	pid_t childpid;
	int pipe1[2];
	int pipe2[2];

	if (pipe(pipe1) <0)
	{
		perror("create pipe1 error");
	}
	if (pipe(pipe2) <0)
	{
		perror("create pipe2 error");
	}
	childpid = fork();
	if (0 ==childpid)
	{
		close(pipe1[1]);
		close(pipe2[0]);
		server(pipe1[0],pipe2[1]);
	}
	close(pipe1[0]);
	close(pipe2[1]);
	child(pipe2[0],pipe1[1]);
	waitpid(childpid,NULL,0);
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
void child(int readfd,int writefd)
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