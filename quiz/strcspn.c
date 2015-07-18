#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) 
{
	char *str = "the groble,view";
	char *p = "nw";
	char *res;
	char input[10] ="abc,df,gh";
	int n;
	n = strcspn(str,p);
	printf("%c",str[n]);
	res  = strtok(input,",");//第一次调用，返回，adc
	if(res)
		printf("%s\n",res);
	res  = strtok(NULL,",");//第二次调用，返回，df
	if(res)
		printf("%s\n",res);
	return 0;
}
