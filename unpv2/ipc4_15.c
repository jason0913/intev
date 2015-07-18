#include "unpipc.h"

int main(int argc, char const *argv[])
{
	size_t n;
	char buff[MAXLINE],command[MAXLINE];
	FILE *fp;

	printf("input a pathname\n");
	fgets(buff,MAXLINE,stdin);
	n = strlen(buff);
	if ('\n' == buff[n-1])
	{
		n--;
	}
	snprintf(command,MAXLINE,"cat %s",buff);
	fp = popen(command,"r");
	if (NULL ==fp)
	{
		perror("popen error");
		exit(-1);
	}
	while(fgets(buff,MAXLINE,fp) != NULL)
	{
		fputs(buff,stdout);
	}
	return 0;
}