
#include <stdio.h>


int arr[1000];
int global =100;
int main(int argc, char const *argv[])
{
	int local_arr[1000]={10};
	int local_arr2[1000];
	char *ptr;
	printf("sizeof(char*) %d\n", sizeof(char *));
	printf("hello world\n");
	return 0;
}
