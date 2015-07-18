#include "unpipc.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

// #define SIGRTMAX (sysconf(_SC_RTSIG_MAX))

typedef void Sigfunc_rt(int,siginfo_t *,void *);

static void sig_rt(int,siginfo_t *,void*);

Sigfunc_rt * signal_rt(int signo,Sigfunc_rt *func,sigset_t *mask);

int main(int argc, char const *argv[])
{
	int i,j;
	pid_t pid;
	sigset_t newset;
	union sigval val;

	printf("SIGRTMIN =%d,SIGRTMAX= %d\n",(int)SIGRTMIN,(int)SIGRTMAX);

	if (0 ==(pid = fork()))
	{
		sigemptyset(&newset);
		sigaddset(&newset,SIGRTMAX);
		sigaddset(&newset,SIGRTMAX-1);
		sigaddset(&newset,SIGRTMAX-2);
		sigprocmask(SIG_BLOCK,&newset,NULL);

		signal_rt(SIGRTMAX,sig_rt,&newset);
		signal_rt(SIGRTMAX-1,sig_rt,&newset);
		signal_rt(SIGRTMAX-2,sig_rt,&newset);

		printf("child sleep 6s------\n");
		sleep(6);
		sigprocmask(SIG_UNBLOCK,&newset,NULL);
		printf("child sleep 3s------\n");
		sleep(3);
		exit(0);
	}
	printf("father sleep 3s------\n");
	sleep(3);
	for (i = SIGRTMAX; i >= SIGRTMAX-2; i--)
	{
		for (j = 0; j <=2; ++j)
		{
			val.sival_int =j;
			sigqueue(pid,i,val);
			printf("send signal %d,val=%d\n", i,j);
		}
	}
	return 0;
}

static void sig_rt(int signo,siginfo_t *info,void *context)
{
	printf("received signal #%d,code =%d,ival=%d\n",
		signo,info->si_code,info->si_value.sival_int);
}

Sigfunc_rt * signal_rt(int signo,Sigfunc_rt *func,sigset_t *mask)
{
	struct sigaction act,oact;

	act.sa_sigaction = func;
	act.sa_mask = *mask;
	act.sa_flags = SA_SIGINFO;

	if (sigaction(signo,&act,&oact) <0)
	{
		return ((Sigfunc_rt*)SIG_ERR);
	}
	return (oact.sa_sigaction);
}