/* 
* @Author: jql
* @Date:   2015-08-16 22:56:08
* @Last Modified by:   jql
* @Last Modified time: 2015-08-16 23:01:51
*/

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

/*
 *声明3个线程
 */
void *thread1_func(void *arg);
void *thread2_func(void *arg);
void *thread3_func(void *arg);
sem_t sem1 ;
sem_t sem2 ;
sem_t sem3 ;

pthread_t thread1 = 0;
pthread_t thread2 = 0;
pthread_t thread3 = 0;

int main(void)
{
    int res = 0;
    
    void *thread_return = (void *)0;
    /*
     *创建3个信号量
     */
    res = sem_init(&sem1, 0, 0);
    if(res != 0)
    {
        perror("fail to create sem1\n");
        exit(EXIT_FAILURE);
    }
    res = sem_init(&sem2, 0, 0);
    if(res != 0)
    {
        perror("fail to create sem2\n");
        exit(EXIT_FAILURE);
    }
    res = sem_init(&sem3, 0, 0);
    if(res != 0)
    {
        perror("fail to create sem3\n");
        exit(EXIT_FAILURE);
    }
    /*
     *创建3个线程
     */ 
    res = pthread_create(&thread1, NULL, thread1_func, (void*)"A");
    if(res != 0)
    {
        perror("fail to create thread1\n");
        exit(EXIT_FAILURE);
    }
    res = pthread_create(&thread2, NULL, thread2_func, (void*)"B");
    if(res != 0)
    {
        perror("fail to create thread2\n");
        exit(EXIT_FAILURE);
    }
    res = pthread_create(&thread3, NULL, thread3_func, (void*)"C");
    if(res != 0)
    {
        perror("fail to create thread3\n");
        exit(EXIT_FAILURE);
    }
    
    res = sem_post(&sem1);
    if(res != 0)
    {
        perror("fail to post sem1\n");
        exit(EXIT_FAILURE);
    }
    
    /*
     *等待线程执行
     */
    printf("wait for thread to finish\n");
    res = pthread_join(thread1, &thread_return);
    if(res != 0)
    {
        perror("fail to jion thread1\n");
        exit(EXIT_FAILURE);
    }
    res = pthread_join(thread2, &thread_return);
    if(res != 0)
    {
        perror("fail to jion thread2\n");
        exit(EXIT_FAILURE);
    } 
    res = pthread_join(thread3, &thread_return);
    if(res != 0)
    {
        perror("fail to jion thread3\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}

void *thread1_func(void *arg)
{
    int reg = 0;
    sem_wait(&sem1);
    if(reg != 0)
    {
        perror("fail to wait sem1\n");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", (char *)arg);
    fflush(stdout);
    sem_post(&sem2);
    sem_destroy(&sem1);
    pthread_exit(0);
}


void *thread2_func(void *arg)
{
    int reg = 0;
    sem_wait(&sem2);
    if(reg != 0)
    {
        perror("fail to wait sem2\n");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", (char*)arg);
    fflush(stdout);
    sem_post(&sem3);
    sem_destroy(&sem2);
    pthread_exit(0);
}


void *thread3_func(void *arg)
{
    int reg = 0;
    sem_wait(&sem3);
    if(reg != 0)
    {
        perror("fail to wait sem1\n");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", (char*)arg);
    fflush(stdout);
    sem_destroy(&sem3);
    pthread_exit(0);
}
