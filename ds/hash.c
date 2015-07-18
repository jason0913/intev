#include "ds.h"

#define FILE_HASH 20

int hash_filename(char *s)
{
	int length = strlen(s);
	return (length + 4*(s[0] + 4*s[length/2])) %FILE_HASH;
}
int main(int argc, char const *argv[])
{
	char *f = "test.txt";
	int hash;
	hash = hash_filename(f);
	printf("test.txt:%d\n", hash);
	return 0;
}