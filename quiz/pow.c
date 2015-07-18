#include <stdio.h>
#include <stdlib.h>

int equal(double n1,double n2)
{
	if ((n1 -n2 > -0.0000001) &&(n1 -n2 <0.0000001))
	{
		return 1;
	}
	else
		return 0;
}

double Power(double base,int exp)
{
	double res = 1.0;
	int i;
	int negitive =0;
	if (equal(base,0.0) && exp <0)
	{
		return 0.0;
	}
	if (exp <0)
	{
		negitive = abs(exp);
	}
	else negitive = exp;
	for (i = 0; i < negitive; ++i)
	{
		res *= base;
	}
	if (exp <0)
	{
		res = 1.0/res;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int i;
	printf("pow = %f\n",Power(-2,-3));
	return 0;
}