#include "unpipc.h"
#include <fcntl.h>
#include <semaphore.h>

#define SEM_NAME "mysem"
#define PATH_MAX 126

/* include px_ipc_name */

char *px_ipc_name(const char *name)
{
        char    *dir, *dst, *slash;
        //分配的空间在哪里释放的哦！@deprecated 
        if ( (dst = (char *)malloc(PATH_MAX)) == NULL)
                return(NULL);

                /* 4can override default directory with environment variable */
        if ( (dir = getenv("PX_IPC_NAME")) == NULL) {
#ifdef  POSIX_IPC_PREFIX
                dir = POSIX_IPC_PREFIX;         /* from "config.h" */
#else
                dir = "/tmp";                           /* default */
#endif
        }
                /* 4dir must end in a slash */
        slash = (dir[strlen(dir) - 1] == '/') ? "" : "/";
        snprintf(dst, PATH_MAX, "%s%s%s", dir, slash, name);

        return(dst);                    /* caller can free() this pointer */
}
/* end px_ipc_name */

char *Px_ipc_name(const char *name)
{
        char    *ptr;
        // gcc -posix -E -dM - </dev/null >
#ifdef linux
        ptr = (char *)name;
#else
        if ( (ptr = px_ipc_name(name)) == NULL)
        	printf("px_ipc_name error for %s", name);
#endif
        return(ptr);
}


int count = 0;

int main(int argc, char const *argv[])
{
	int i,nloop;
	sem_t *mutex;

	if (2 != argc)
	{
		printf("Usage incr1 <nloop>\n");
		exit(-1);
	}
	nloop = atoi(argv[1]);

	mutex = sem_open(Px_ipc_name(SEM_NAME),O_CREAT|O_EXCL,FILE_MODE,1);
	sem_unlink(Px_ipc_name(SEM_NAME));

	setbuf(stdout,NULL);
	if (0 ==fork())
	{
		for (i = 0; i < nloop; ++i)
		{
			sem_wait(mutex);
			printf("child %ld: count = %d\n", getpid(),count++);
			sem_post(mutex);
		}
		exit(0);
	}
	for (i = 0; i < nloop; ++i)
	{
		sem_wait(mutex);
		printf("parent %ld, count= %d\n", getpid(),count++);
		sem_post(mutex);
	}
	return 0;
}