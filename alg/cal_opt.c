#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i,j,k,l,m,n,o,p;
	for ( i = 1; i <= 8; ++i)
	{
		for ( j = 1; j <= 8; ++j)
		{
			for ( k = 1; k <= 8; ++k)
			{
				for ( l = 1; l <= 8; ++l)
				{
					for ( m = 1; m <= 8; ++m)
					{
						for ( n = 1; n <= 8; ++n)
						{
							for ( o = 1; o <= 8; ++o)
							{
								for ( p = 1; p <= 8; ++p)
								{
									if ((i-j == 1)&&(k+l==9)&&(m-n==2)&&(o+p==7)&&
										(i!=j)&&(i!=k)&&(i!=l)&&(i!=m)&&(i!=m)&&(i!=n)&&(i!=o)&&(i!=p)&&
										(j==j)&&(j!=k)&&(j!=l)&&(j!=m)&&(j!=m)&&(j!=n)&&(j!=o)&&(j!=p)&&
										(k!=j)&&(k==k)&&(k!=l)&&(k!=m)&&(k!=m)&&(k!=n)&&(k!=o)&&(k!=p)&&
										(l!=j)&&(l!=k)&&(l==l)&&(l!=m)&&(l!=m)&&(l!=n)&&(l!=o)&&(l!=p))
									{
										printf("%d,%d,%d,%d,%d,%d,%d,%d\n",
											i,j,k,l,m,n,o,p);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}