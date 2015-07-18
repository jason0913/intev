#include "unpipc.h"
#include <pthread.h>
#include <fcntl.h>
#include <semaphore.h>

#define NBUFF 10
#define SEM_MUTEX "mutex"
#define SEM_NEMPTY "nempty"
#define SEM_NSTORED "nstored"
#define PATH_MAX 128

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

int nitems;
struct 
{
	int buf[NBUFF];
	sem_t mutex,nempty,nstored;

}shared;

void *produce(void *);
void *consume(void *);

int main(int argc, char const *argv[])
{
	pthread_t tid_consume,tid_produce;

	if (2 != argc)
	{
		printf("Usage: program items\n");
		exit(-1);
	}
	nitems = atoi(argv[1]);

	sem_init(&shared.mutex ,0,1);
	sem_init(&shared.nempty ,0,NBUFF);
	sem_init(&shared.nstored ,0,0);

	pthread_setconcurrency(2);
	pthread_create(&tid_produce,NULL,produce,NULL);
	pthread_create(&tid_consume,NULL,consume,NULL);

	pthread_join(tid_consume,NULL);
	pthread_join(tid_produce,NULL);

	sem_destroy(&shared.mutex);
	sem_destroy(&shared.nempty);
	sem_destroy(&shared.nstored);
	return 0;
}

void *produce(void *arg)
{
	int i;
	for (i = 0; i < nitems; ++i)
	{
		sem_wait(&shared.nempty);
		sem_wait(&shared.mutex);
		printf("produce %ld,put %d\n", (long)pthread_self(),i);
		shared.buf[i%NBUFF] =i;
		sem_post(&shared.mutex);
		sem_post(&shared.nstored);

	}
	return NULL;
}

void *consume(void *arg)
{
	int i;
	for (i = 0; i < nitems; ++i)
	{
		sem_wait(&shared.nstored);
		sem_wait(&shared.mutex);
		if (shared.buf[i %NBUFF] == i)
		{
			printf("consume %ld,get %d\n", (long)pthread_self(),i);
			printf("buf[%d] = %d,\n", i,shared.buf[i%NBUFF]);
		}
		sem_post(&shared.mutex);
		sem_post(&shared.nempty);
	}
	return NULL;
}