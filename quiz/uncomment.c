#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) 
{
	char line[1000];
	FILE *fp;
	char *begin;
	if (argc != 2)
	{
		printf("usage: uncomment filename\n");
		return -1;
	}
	fp = fopen("testuncomment.c","r+");
	if (fp == NULL)
	{
		perror("fopen file error");
		return -1;
	}
	else
		printf("open file success\n");
	
	while(fgets(line, sizeof(line), fp) != NULL)
	{
		//printf("%s",line);
		begin = strchr(line,'*');
		//printf("star at :%s",begin);
		if (begin != NULL)
		{
			*begin = '\0';
			/* while(*++begin != '*')
			{
				//printf("%c ",*begin);
				*begin = ' ';
				//begin ++;
			} */
		} 
		printf("%s",line);
		fprintf(fp, "%s",line);
	}
	fclose(fp);
	return 0;
}