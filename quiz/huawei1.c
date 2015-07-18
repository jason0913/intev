#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

// 输入m个字符串，长度大于n则截断，不够的部分补零

int main()
{
	int m,n,i,j;
	int len ;
	int times;
	char str[100];
	char *p;
	p = str;
	printf("Input m:\n");
	scanf("%d",&m);
	printf("Input n:\n");
	scanf("%d",&n);
	for(j = 0; j < m ; j++)
	{
		printf("Input a string\n");
		scanf("%s",p);
		//gets(p);         // end with \n
		len = strlen(str);
		str[len +1] = '\0';
		times = 0 ;
		if(len > n)
		{
			for	(i = 0 ; i < len -1 ;i++)
			{
				printf("%c",str[i]);
				if((i +1) % n == 0)
					{
						printf("\n");
						times ++;
					}				
			}
			for(i = 0 ; i < len - n * times; i ++)
			{
				printf("0");
			}				
		}
		if(len <= n)
		{	
			printf("%s",str);
		
			for( i = 0 ; i < n - len ; i ++)
			{
				printf("0");
			}
		}		
	}
}