#include "ds.h"

void print_arr(char arr[])
{
	printf("&arr:%ld &(arr[0]):%ld &(arr[1]) %d\n",
	&arr,&(arr[0]),&(arr[1]));
}

void print_ptr(char *ptr)
{
	printf("&ptr:%ld &(ptr[0]):%ld &(ptr[1]) %d\n",
	&ptr,&(ptr[0]),&(ptr[1]));
}

char ga[10]="abcs";

int main(int argc, char const *argv[])
{
	print_arr(ga);
	print_ptr(ga);
	return 0;
}