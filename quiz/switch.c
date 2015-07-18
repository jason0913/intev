#include <stdio.h>
#include <stdlib.h>

//switch 语句中表达式必须是整数，或者字符（可以转化整数）
int main(int argc, char* argv[]) 
{
	float f;
	scanf("%f",&f);
	switch (f) 
	{
		case 1.1:
				printf("case 1.1\n");
				break;
		  default:
				printf("not 1.1\n");
				break;
	}
	return 0;
}