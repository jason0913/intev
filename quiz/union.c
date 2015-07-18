/*************************************************************************
    > File Name: union.c
    > Author: liujunq2
    > Mail: liujunq2@163.com 
    > Created Time: Mon 16 Mar 2015 09:24:20 AM EDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(int argc, const char *argv[])
{
	struct un
	{
		short a;
		//char b[sizeof(short)];
		char b;
	};
	struct un s;
	s.a = 0x0102;
	printf("s.a:%x,s.b%x\n",s.a,s.b);
	return 0;
}
