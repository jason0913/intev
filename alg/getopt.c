#include <stdio.h>
#include <unistd.h>

int main(int argc, char  *argv[])
{
	int ch;
	char *opt_arg;

	while((ch = getopt(argc,argv,"ab:l:")) != -1)
	{
		switch(ch)
		{
			case 'a':
				printf("all information\n");
				break;
			case 'b':
				printf("brief information %s\n",optarg);
				break;
			case 'l':
				opt_arg = optarg;
				printf("list args %s\n", optarg);
				break;
			default:
				;
		}
	}
	return 0;
}