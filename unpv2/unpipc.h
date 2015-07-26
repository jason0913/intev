#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAXLINE 4096
#define FILE_MODE (S_IRUSR |S_IWUSR |S_IRGRP|S_IWGRP |S_IROTH)

// for system v msg run
#define MSG_R O_RDWR
#define MSG_W O_RDWR

#define SVSEM_MODE (SEM_R|SEM_A| SEM_R>>3 |SEM_R>>6) 
#define SVMSG_MODE (MSG_R|MSG_W| MSG_R>>3 |MSG_R>>6) 
#define SVSHM_MODE (SHM_R|SHM_W| SHM_R>>3 |SHM_R>>6) 
