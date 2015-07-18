/*************************************************************************
    > File Name: fork.c
    > Author: liujunq2
    > Mail: liujunq2@163.com 
    > Created Time: Fri 15 Aug 2014 08:27:06 AM EDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	int i;
	printf("======");
	for( i = 0;  i < 2; i++)
	{
		fork();
		printf("*\n");
		//without \n then printf 8 * ,because function printf if line buffered
		
	}
	exit(0);
}

