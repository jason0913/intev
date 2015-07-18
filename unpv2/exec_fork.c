/*
 * =====================================================================================
 *
 *       Filename:  exec_fork.c
 *
 *    Description:  is child and father exec at same time	
 *
 *        Version:  1.0
 *        Created:  05/24/2015 09:11:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "unpipc.h"

int main(int argc, const char *argv[])
{
	pid_t pid;
	if ((pid = fork())==0) {
		printf("child running\n");
		sleep(3);
		printf("chiid end\n");
		exit(0);
	}
	printf("father running\n");
	sleep(3);
	printf("father end\n");
	return 0;
}
