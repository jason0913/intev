#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 简易计算器
int main(int argc, char* argv[]) 
{
	char str[20];
	int a,b,res;
	char c;
	while(gets(str) != NULL)
	{
		if (sscanf(str,"%d %c %d",&a,&c,&b) != 3)
			printf("sscanf error\n");
		if (!(a >=0 && a <=9) && !(b >=0 && b <=9))
		{
			printf("Input number\n");
			
		}
		else
		{
			switch (c) 
			{
				case '+':
						res = a + b ;
						break;
				case '-':
						res = a - b ;
						break;
				case '*':
						res = a * b ;
						break;
				case '/':
						if (b == 0)
						{
							printf("div can not equal 0\n");
							return -1;
						} 
						else
						{
							res = a / b ;
							break;
						}					
				default:
						printf("Invalid operator\n");
						break;
			}	
		}
		memset(str,0,20);				
	}
	printf("res = %d",res);
	return 0;
}