#include <stdio.h>
#include <stdlib.h>

int max(int x,int y)
{
	return x>y? x:y;
}
int main(int argc,  const char *argv[])
{
	int (*p)(int ,int);
	// same effective;
	// p = max;
	p = &max;
	printf("max =%x,&max=%d\n", max,&max);
	int a,b,c,d;
	printf("Input 3 interger\n");
	scanf("%d%d%d",&a,&b,&c);
	d = (*p)((*p)(a,b),c);
	printf("bigest %d\n",d);
	return 0;
}