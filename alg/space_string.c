#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// strings betwwen no comma ,then merge them
int main(int argc, char const *argv[])
{
	char *avaliable_resource[]=
	{
		"color monitor",
		"big disk",
		"cray"
		"online drwaing",
		"mouse",
		"keboard",
	};
	int len,i;
	len = sizeof(avaliable_resource)/sizeof(avaliable_resource[0]);
	for (i = 0; i < len; ++i)
	{
		printf("avaliable_resource[%d]=%s\n", i,avaliable_resource[i]);
	}
	return 0;
}