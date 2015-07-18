#include <stdio.h>
#include <stdlib.h>

void func(int (*)[5])
{

}

int main(int argc, char const *argv[])
{
	int v[2][10]=
	{{1,2,3,4,5,6,7,8,9,10},
	{11,12,13,14,15,16,17,18,19,20}};

	int (*a)[10] =v;
	printf("**a =%d\n",**a);
	printf("*a =%x\n",*a);
	a++;
	printf("**a =%d\n",**a);
	printf("*a =%x\n",*a);
	printf("v = %x\n", v);
	printf("v+1 = %x\n", v+1);
	printf("**v = %x\n", **v);
	printf("*v = %x\n", *v);
	printf("*v +1 = %x\n", *v+1);
	printf("*(*v +1) = %x\n", *(*v+1));

	printf("--------------\n");
	int b[2]={1,2};
	int p =5;
	int p2 =6;
	int *page = &p;
	int *page2 = &p2;
	int *ptr[5];
	ptr[0]=&p;
	ptr[1]=page2;
	printf("*ptr[0] %d\n", *ptr[0]);
	printf("*ptr[1] %d\n", *ptr[1]);
	printf("*page %d\n", *page);
	printf("--------------\n");
	int c[]= {1,2,3,4,5};
	int *pt = (int*)(&c+1);
	printf("%d\n", *(pt-1));
	pt = (int*)(c+1);
	printf("%d\n", *(pt-1));

	// &c become line ptr
	func(&c);
	printf("------------\n");
	printf("&c[0] =%x\n", &c[0]);
	printf("c =%x\n", c);
	printf("c+1 =%x\n", c+1);
	printf("&c =%x\n", &c);
	printf("&c+1 =%x\n", &c+1);
	printf("sizeof(c) =%d\n", sizeof(c));
	printf("sizeof(&c) =%d\n", sizeof(&c));
	return 0;
}