<<<<<<< HEAD
#include <stdio.h>

int main(int argc, char** argv) 
{
	int i = 0;
	for ( i= 0; i < argc; ++i) {
		printf("argv = %s \n",argv[i]);
		printf("argv - :%c \n",argv[i][0]);
	}
	return 0;
=======
#include <stdio.h>

int main(int argc, char** argv) 
{
	int i = 0;
	for ( i= 0; i < argc; ++i) {
		printf("argv = %s \n",argv[i]);
		printf("argv - :%c \n",argv[i][0]);
	}
	return 0;
>>>>>>> 24dcaf1987354c8e05bb41117ee531c8d0335611
}