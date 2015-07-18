#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// create N process by fork

#define N 3

void Child_Func()
{
	printf("childpid %d,ppid %d\n", getpid(),getppid());

}
int main(int argc, char const *argv[])
{
	int i;
	int stat;
	pid_t childpid,pid;

	for (i = 0; i < N; ++i)
	{
		if ((childpid=fork()) ==0)
		{
			Child_Func();
			sleep(1);
			// if not have exit,then 
			// child will fork too
			exit(0);
		}
	}
	printf("father pid %d\n", getpid());
	while((pid = waitpid(-1,&stat,WNOHANG)) >0)
	{
		printf("child %d terminated\n", pid);
	}
	return 0;
}