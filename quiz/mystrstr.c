#include <stdio.h>
#include <string.h>

// 字符串搜索函数
int mystrstr(char *search,char *find)
{
	int len;
	int num = 0;
	len = strlen(find);
	printf("len = %d\n",len);
	if (strlen(find) == 0)
	{
		return 0;
	}
	/*如果在strncmp中比较的len大于实际的长度，则一定不相等，返回非零
	比如，strncmp（stst，st，1000），只有在比较stst中的第二个st时，才返回相等
	*/
	for ( ; *search; search++)
	{
		if(*search == *find && !strncmp(search,find,len))
			num++;
	}
	return num;
}
int main(int argc, char* argv[]) 
{
	char string[100];
	char substr[10];
	printf("Enter a string\n");
	gets(string);
	printf("Enter sub string\n");
	gets(substr);
	printf("strncmp %d\n",strncmp(string,substr,1000));
	if (mystrstr(string,substr) == 0)
	{
		printf("not find\n");
	} 
	else		
	{
		printf("find %d substr\n",mystrstr(string,substr));
	}
	return 0;
}