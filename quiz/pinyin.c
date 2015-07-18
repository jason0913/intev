#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 将0-9的拼音转换成数字
int main()
{
	char pinyin[100];
	char *p = pinyin;
	char shuzi[5] ="yi";
	int i = 0;
	
	memset(pinyin,sizeof(pinyin),'\0');
	memset(shuzi,sizeof(shuzi),'\0');
	printf("Input a pinyin\n");
	scanf("%s",pinyin);
	while(*p != '\0')
	{
		shuzi[i] = *p;
		p ++;
		i ++;
		if( i == 2)
		{
			shuzi[2] = '\0';
			if(strcmp("yi",shuzi) == 0)
			{
				printf("1");
				i = 0;
				memset(shuzi,sizeof(shuzi),'\0');
			}
			if(strcmp("er",shuzi) == 0)
			{
				printf("2");
				i = 0;
				memset(shuzi,sizeof(shuzi),'\0');
			}
			if(strcmp("si",shuzi) == 0)
			{
				printf("4");
				i = 0;
				memset(shuzi,sizeof(shuzi),'\0');
			}
			if(strcmp("wu",shuzi) == 0)
			{
				printf("5");
				i = 0;
				memset(shuzi,sizeof(shuzi),'\0');
			}
			if(strcmp("qi",shuzi) == 0)
			{
				printf("7");
				i = 0;
				memset(shuzi,sizeof(shuzi),'\0');
			}
			if(strcmp("ba",shuzi) == 0)
			{
				printf("8");
				i = 0;
				memset(shuzi,sizeof(shuzi),'\0');
			}			
		}
		if (i == 3)
		{
			shuzi[3] = '\0';
			if(strcmp("san",shuzi) == 0)
			{
				printf("3");
				i = 0;
				memset(shuzi,sizeof(shuzi)+1,'\0');
			}
			if(strcmp("liu",shuzi) == 0)
			{
				printf("6");
				i = 0;
				memset(shuzi,sizeof(shuzi)+1,'\0');
			}
			if(strcmp("jiu",shuzi) == 0)
			{
				printf("9");
				i = 0;
				memset(shuzi,sizeof(shuzi)+1,'\0');
			}
			
		}
	}
	printf("\n");
	exit(0);
}
