/* 
* @Author: jql
* @Date:   2015-08-03 07:55:08
* @Last Modified by:   jql
* @Last Modified time: 2015-08-03 08:33:46
  why signal return a func ptr? its save pre callback func
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_int(int signo)
{
	printf("got SIGINT\n");
	return;
}
void (*ptrf)(int );
int main() {

	ptrf=signal(SIGINT,sig_int);
	*ptrf;

	sigset_t sgset;
	sigemptyset(&sgset);
	sigaddset(&sgset,SIGINT);
	printf("SIG_BLOCK,sleep 10 and SIG_UNBLOCK\n");
	sigprocmask(SIG_BLOCK,&sgset,NULL);
	printf("crtl +c\n");

		sleep(10);
	printf("SIG_UNBLOCK\n");
	sigprocmask(SIG_UNBLOCK,&sgset,NULL);
    return 0;
}