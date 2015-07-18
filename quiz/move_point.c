#include <stdio.h>
#include <string.h>

// 形参指针的移动,对实参没有影响
char * movepoint(char *p)
{
	printf("befroe p = %x \n",p);
	++p;
	printf("after p = %x \n",p);
	return p;
}
int main(int argc, char* argv[]) 
{
	char* s1 = (char*)malloc(10*sizeof(char));
	printf("befroe s1 = %x \n",s1);
	movepoint(s1);
	printf("in return %x",movepoint(s1));
	printf("after s1 = %x \n",s1);
	return 0;
}