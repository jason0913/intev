#include <stdio.h>
#include <stdlib.h>

struct S
{
	int i;
	int *p;
};

int main(int argc, char const *argv[])
{
	struct  S s;
	int *p = &s.i;
	p[0] =4;
	p[1] = 3;
	s.p = p;
	s.p[1] = 1;
	s.p[0] = 2;
	return 0;
}