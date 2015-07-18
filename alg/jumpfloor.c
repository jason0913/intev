#include <stdio.h>
#include <stdlib.h>

int jumpfloor(target)
{
	if (1 == target)
	{
		return 1;
	}
	else if (2 == target)
	{
		return 2;
	}
	else
		return jumpfloor(target-1)+jumpfloor(target-2);
}
int main(int argc, char const *argv[])
{
	int target;
	int times;
	scanf("%d",&target);
	times = jumpfloor(target);
	printf("times =%d\n",times);
	return 0;
}