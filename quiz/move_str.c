#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) 
{
	char s1[100] = "//this commentary slash will move";
	char* p;
	printf("befroe s1 = %s \n",s1);
	p = strstr(s1,"//");
	strcpy(s1,p + 2);
	printf("after s1 = %s \n",s1);
	return 0;
}