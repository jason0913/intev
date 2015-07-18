#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

void loopmove(char *pstr,int nstep)
{
	int n = strlen(pstr) -nstep;
	char tmp[MAXLEN];
	strcpy(tmp,pstr+n);
	strncpy(tmp + nstep,pstr,n);
	// *(tmp +strlen(pstr)) ='\0';
	strcpy(pstr,tmp);
}

int main(int argc, char const *argv[])
{
	char str[MAXLEN] = "abcdef";
	loopmove(str,2);
	printf("%s\n", str);
	return 0;
}