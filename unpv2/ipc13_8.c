#include "unpipc.h"
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <semaphore.h>

#define PATH_MAX 100

struct shmstruct
{
	int count;
};
sem_t *mutex;

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

int main(int argc, char const *argv[])
{
        int fd,i,nloop;
        pid_t pid;
        struct shmstruct *ptr;
        if (4 != argc)
        {
                printf("Usage:client <shmname> <semname> <nloop>\n");
                exit(-1);
        }
        nloop = atoi(argv[3]);
        fd = shm_open(Px_ipc_name(argv[1]),O_RDWR,FILE_MODE);
        ptr = mmap(NULL,sizeof(struct shmstruct),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
        close(fd);

        mutex = sem_open(Px_ipc_name(argv[2]),0);
        pid = getpid();
        for (i = 0; i < nloop; ++i)
        {
                sem_wait(mutex);
                printf("pid %d,:%d\n", (long)pid,ptr->count++);
                sem_post(mutex);
        }
        return 0;
}