/* 
* @Author: jql
* @Date:   2015-08-26 03:15:05
* @Last Modified by:   jql
* @Last Modified time: 2015-08-26 03:24:04
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

	printf("main-----\n");
	printf("getpgrp %d\n", getpgrp());
	printf("getsid %d\n", getsid(getpid()));
	printf("-------\n");
	pid_t pid;
	if (fork() >0)
	{
		exit(0);
	}
	else
	{
		sleep(2);
		printf("child:\n");
		printf("getpgrp %d\n", getpgrp());
		printf("getsid %d\n",getsid(getpid()));
		printf("----setsid-----\n");
		setsid();
		printf("getpgrp %d\n", getpgrp());
		printf("getsid %d\n",getsid(getpid()));
		while(1)
		{
			sleep(1);
		}
	}
    return 0;
}