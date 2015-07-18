/*
fork N children and child never return, they into loop
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NCHILD 3

static pid_t *pids;

pid_t child_make()
{
	pid_t pid;
	if ((pid = fork()) >0)
	{
		return pid;
	}
	// child nerver retturn;
	printf("fork child :pid = %d, ppid = %d\n", getpid(),getppid());
	for(;;)
	{
		printf("child :pid = %d\n", getpid());
		sleep(1); //loop;
	}
}
int main(int argc, char const *argv[])
{
	int i;
	
	pids = (pid_t *)calloc(NCHILD,sizeof(pid_t));
	for (i = 0; i < NCHILD; ++i)
	{
		pids[i] = child_make();
	}
	printf("pid = %d, ppid = %d\n", getpid(),getppid());
	return 0;
}