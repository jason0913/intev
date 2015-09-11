/* 
* @Author: jql
* @Date:   2015-08-12 05:53:26
* @Last Modified by:   jql
* @Last Modified time: 2015-08-12 06:03:30
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sig_alrm(int signo)
{
	printf("got SIGALRM\n");
}
int main() {

	printf("raise alarm in 5 sec\n");
	// signal(SIGALRM,sig_alrm);  //not have this sentence,then follow printf dont exec
	alarm(5);
	pause();
	printf("done this sentence\n");
    return 0;
}