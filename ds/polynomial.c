#include "ds.h"

//  Polynomai operator
#define MAXDEGREE 20

typedef struct poly
{
	int coeffarry[MAXDEGREE+1];
	int highpower;
}*Polynomail;

void zero_poly(Polynomail poly)
{
	int i ;
	for (i = 0; i <= MAXDEGREE; ++i)
	{
		poly->coeffarry[i] = 0;
	}
	poly->highpower = 0;
}

void add_poly(Polynomail p1,Polynomail p2,Polynomail psum)
{
	int i ;
	zero_poly(psum);
	psum->highpower = p1->highpower > p2->highpower ? p1->highpower:p2->highpower;
	for (i = 0; i <= psum->highpower; ++i)
	{
		psum->coeffarry[i] = p1->coeffarry[i] + p2->coeffarry[i];
	}
}

void mult_poly(Polynomail p1,Polynomail p2,Polynomail pmult)
{
	int i,j;
	zero_poly(pmult);
	pmult->highpower = p1->highpower + p2->highpower;
	if (pmult->highpower > MAXDEGREE)
	{
		printf("MAXDEGREE over\n");
		return ;
	}
	for (i = 0; i <= p1->highpower; ++i)
	{
		for (j = 0; j < p2->highpower; ++j)
		{
			pmult->coeffarry[i+j]= p1->coeffarry[i]+p2->coeffarry[j];

		}
	}

}
