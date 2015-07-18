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

void client(int,int);

int main(int argc, char const *argv[])
{
	int readid,writefd;

	readid = msgget(MQ_KEY1,0);
	writefd= msgget(MQ_KEY2,0);

	if (readid <0 || writefd <0)
	{
		perror("msgget error");
		exit(-1);
	}
	client(readid,writefd);

	msgctl(readid,IPC_RMID,NULL);
	msgctl(writefd,IPC_RMID,NULL);
	return 0;
}
void client(int readfd,int writefd)
{
	size_t len;
	ssize_t n;
	struct msgbuf *buf;


	printf("client:input path\n");
	fgets(buf,MAXLINE,stdin);
	len = strlen(buf);
	if ('\n' == buf[len-1])
	{
		len--;
	}
	if (mesg_send(writefd,buf)<0)
	{
		perror("write writefd error");
		return;
	}
	printf("client:read from server:\n");
	while((n = mesg_recv(readfd,buf)) >0)
	{
		fputs(buf,stdout);
	}
}