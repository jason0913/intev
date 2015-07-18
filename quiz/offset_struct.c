#include <stdio.h>

/*
struct member offset
*/

#define FIND(struc,e) (size_t)&(((struc *)0)->e)

#define FIN(st,e) (size_t)&(((struct stuent *)st)->e)
struct student
{
	int a;
	char b[20];
	double c;
};

union teacher
{
	int e;
	char f[20];
	double g;
};


int main(int argc, char const *argv[])
{
	int *p1;
	struct student *p2;
	printf("*p1 = %d\n", sizeof(p1));
	printf("*p2 = %d\n", sizeof(p2));
	struct student st;
	unsigned int offset;
	printf("------struct----\n");
	offset = FIND(student,a);
	printf("a offset=%d\n", offset);

	offset = FIND(student,b);
	printf("b offset=%d\n", offset);

	offset = FIND(student,c);
	printf("c offset=%d\n", offset);

	/*printf("------struct 2----\n");
	offset = FIN(st,a);
	printf("a offset=%d\n", offset);

	offset = FIN(st,b);
	printf("b offset=%d\n", offset);

	offset = FIN(st,c);
	printf("c offset=%d\n", offset);*/

	printf("------union-----\n");
	offset = FIND(teacher,e);
	printf("e offset=%d\n", offset);

	offset = FIND(teacher,f);
	printf("f offset=%d\n", offset);

	offset = FIND(teacher,g);
	printf("g offset=%d\n", offset);
	return 0;
}