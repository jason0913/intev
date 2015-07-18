#include <stdio.h>
#include <stdlib.h>

// 将字符串中的空格转换成逗号

int main()
{
	int c;
	int flag = 0;
	while((c = getchar()) != EOF)
	{
		if(c == ' ')
		{	
			if(flag == 0)
				putchar(',');
			flag = 1;
		}			
		else
		{
			putchar(c);
			flag = 0;
		}			
	}
	return 0;
}