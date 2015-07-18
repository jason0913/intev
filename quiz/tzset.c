#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) 
{
	time_t tm;
	putenv("TZ=PST8PDT");
	tzset();
	time(&tm);
	printf("current time =%s",asctime(localtime(&tm)));
	return 0;
}