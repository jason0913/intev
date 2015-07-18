#include <stdio.h>
#include <string.h>
// 检验IP地址是否合法
int main(void) 
{
	char str[31],temp[31];
	int a,b,c,d;
	while(gets(str)!=NULL)
	{	
		printf("str = %s\n",str);
		if(sscanf(str, "%d.%d.%d.%d",&a,&b,&c,&d)==4 && a>=0 && a<=255 && b>=0 && b<=255 && c>=0 && c<=255 && d>=0 && d<=255)
		{
			sprintf(temp, "%d.%d.%d.%d",a,b,c,d);    //把格式化的数据写入字符串temp
			if(strcmp(temp,str)==0) 
			{
				printf("YES\n"); 
			} 
			else
			{
				printf("NO\n"); 
			}
		}
		else 
		{
			printf("NO\n");
		}
	}
	return 0; 
}