#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	int i;
	for (int i = 0; i < 3; ++i)
	{
		if (0 ==(pid = fork()))
		{
			sleep(1);
			break;
		}
	}
	printf("pid = %d ppid =%d\n", getpid(),getppid());
	while(wait(NULL))
		;
	return 0;
}