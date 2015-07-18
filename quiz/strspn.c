#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) 
{
	char *str = "linux is i383/486";
	printf("%d\n",strspn(str,"linux"));
	printf("%d\n",strspn(str,"is"));
	return 0;
}