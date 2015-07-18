#include "unpipc.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <sys/ipc.h>

#define MQ_KEY1 1234L
#define MQ_KEY2 2345L
#define MAXMESGDATA 1000

struct mymesg
{
	long mesg_len;
	long mesg_type;
	char mesg_data[MAXMESGDATA];
};

void server(int,int);

int main(int argc, char const *argv[])
{
	int readid,writefd;

	readid = msgget(MQ_KEY1,SVMSG_MODE|IPC_CREAT);
	writefd= msgget(MQ_KEY2,SVMSG_MODE|IPC_CREAT);

	if (readid <0 || writefd <0)
	{
		perror("msgget error");
		exit(-1);
	}

	server(readid,writefd);
	return 0;
}

ssize_t mesg_send(int id,struct mymesg *mptr)
{
	return (msgsnd(id,&(mptr->mesg_type),mptr->mesg_len));
}

ssize_t mesg_recv(int id,struct mymesg *mptr)
{
	ssize_t n;

	n = msgrcv(int,&(mptr->mesg_type),MAXMESGDATA,mptr->mesg_type,0);
	mptr->mesg_len =n;
	return n;
}

void server(int readfd,int writefd)
{
	int fd;
	struct mymesg * buf;
	ssize_t n;

	if ((n = mesg_recv(readfd,buf))==0)
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
		mesg_send(writefd,buf);
	}
	else
	{
		while((n = read(fd,buf,MAXLINE)) >0)
		{
			mesg_send(writefd,buf);
		}
		close(fd);
	}
}