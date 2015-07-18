#include "alg.h"
#include <signal.h>
#include <setjmp.h>

jmp_buf buf;

void handler(int signo)
{
	printf("Got SIGINT,in handler func\n");
	longjmp(buf,1);
	printf("back from handler,not exec");
}

int main(int argc, char const *argv[])
{
	if (signal(SIGINT,handler) == SIG_ERR)
	{
		perror("singal SIGINT error");
		return -1;
	}
	if (setjmp(buf))
	{
		printf("back from handler,in main\n");
		return 0;
	}
	else
		printf("first though\n");
	loop:
		goto loop;
	return 0;
}