#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) 
{
	char *ptr;
	int i = 0;
	printf("ptr = %d\n",sizeof(ptr));
	for ( i= 0; i < 102400; ++i) 
	{
		ptr = malloc(102400*sizeof(char));
	}
	printf("ptr = %d\n",sizeof(ptr));
	return 0;
}