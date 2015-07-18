#include "ds.h"

void set_val(int *j)
{
	*j =100;
}
int main(int argc, char const *argv[])
{
	int i = 0;
	set_val(&i);
	printf("i = %d\n", i);
	return 0;
}