#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) 
{
	char str[] = "root:123:root:/bin/bash";
	char* buf;
	char* token;
	buf = str;
	while((token = strsep(&buf,":")) != NULL)
	{
		printf("token =%s\n",token);
	}
	return 0;
}