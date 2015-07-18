#include "ds.h"

int main(int argc, char const *argv[])
{
	char *ca[3]={"abc","def","hi"};
	printf("sizeof(ca): %d, sizeof('a'):%d sizeof(char):%d\n", 
		sizeof(ca),sizeof('a'),sizeof(char));
	return 0;
}