#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

#define MAXLEN 100
int main(int argc, char* argv[]) 
{
	char strdir[100];
	if (getcwd(strdir,MAXLEN) == NULL)
	{
		perror("getcwd error");
		
	}
	printf("current dir:%s",strdir);
	if (daemon(1,1) < 0)
	{
		perror("daemon error");
	}
	sleep(3);
	if (getcwd(strdir,MAXLEN) == NULL)
	{
		perror("getcwd error");
		
	}
	printf("after dir:%s",strdir);
	return 0;
}