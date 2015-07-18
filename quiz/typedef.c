#include <stdio.h>
#include <stdlib.h>

typedef char * PTR;
int main(int argc, char* argv[]) 
{
	PTR p = "hello ptr\n";
	printf("%s ",p);
	return 0;
}