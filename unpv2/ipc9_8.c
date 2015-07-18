#include "unpipc.h"
#include <fcntl.h>
#include <time.h>
#include <sys/time.h>

char *gf_time(void)
{

	struct timeval tv;
	static char str[30];
	char *ptr;
	if (gettimeofday(&tv, NULL) < 0)
		perror("gettimeofday error");
	ptr = ctime(&tv.tv_sec);
	strcpy(str, &ptr[11]);
	/* Fri Sep 13 00:00:00 1986\n\0 */
	/* 0123456789012345678901234 5  */
	snprintf(str+8, sizeof(str)-8, ".%06ld", tv.tv_usec);
	return(str);

}
char *Gf_time(void)
{
	return(gf_time());
}

#define write_lock(fd,offset,whence,len) \
	lock_reg(fd,F_SETLK,F_WRLCK,offset,whence,len)

#define read_lock(fd,offset,whence,len) \
	lock_reg(fd,F_SETLK,F_RDLCK,offset,whence,len)

#define un_lock(fd,offset,whence,len) \
	lock_reg(fd,F_SETLK,F_UNLCK,offset,whence,len)

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
	int fd;

	fd = open("test.data",O_RDWR|O_CREAT,0666);
	if (fd <0)
	{
		perror("open file error");
		exit(-1);
	}

	read_lock(fd,0,SEEK_SET,0);
	printf("%s ,father has locked\n", gf_time());

	// first child
	if (fork() ==0)
	{
		sleep(1);
		printf("%s first child try to obtain write lock\n", gf_time());
		write_lock(fd,0,SEEK_SET,0);
		printf("%s first child obtain write lock\n", gf_time());
		sleep(2);
		un_lock(fd,0,SEEK_SET,0);
		printf("%s first child release write lock\n", gf_time());
		exit(0);
	}
	// second child
	if (fork() ==0)
	{
		sleep(3);
		printf("%s second child try to obtain read lock\n", gf_time());
		read_lock(fd,0,SEEK_SET,0);
		printf("%s second child obtain read lock\n", gf_time());
		sleep(4);
		un_lock(fd,0,SEEK_SET,0);
		printf("%s second child release read lock\n", gf_time());
		exit(0);
	}
	sleep(5);
	un_lock(fd,0,SEEK_SET,0);
	printf("%s:parent release read_lock\n", gf_time());
	return 0;
}