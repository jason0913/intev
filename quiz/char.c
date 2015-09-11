#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 255

int main(int argc, char const *argv[])
{
	char p[MAX+1];
	// char ch;
	unsigned char ch;
	int n=10;
	char a[n];

	for (ch = 0; ch <= MAX; ++ch)
	{
		p[ch] = ch;
		printf("%c ", ch);
		printf("ch = %d ", ch);
		// sleep(1);
	}
	return 0;
}