#include "ds.h"

int main(int argc, char const *argv[])
{
	char str[20];
	char str2[20];
	int arr[20];
	int j,i=0;
	int tmp,ch;
	// enter string end with "\n",accept blank,etc
	printf("enter string with space,end with \\n\n");
	scanf("%[^\n]",str);
	printf("str is:%s\n", str);

	printf("enter string with space,end with space\n");
	scanf("%[^' ']",str2);
	printf("str is:%s\n", str2);

	// seloution 1
	printf("enter nums with space,end with \\n\n");
	while(1)
	{
		scanf("%d",&tmp);
		ch = getchar();
		arr[i] = tmp;
		i++;
		if ('\n' == ch)
		{
			break;
		}
	}
	for (j = 0; j < i; ++j)
	{
		printf("%d ", arr[j]);
	}
	// seloution 2
	/*printf("enter nums with space,end with \\n\n");
	while((scanf("%d",&arr[i]) != EOF) && ((ch=getchar())!='\n'))
	{
		//printf("ch = %c", ch);
		i++;
	}
	for (j = 0; j <= i; ++j)
	{
		printf("%d ", arr[j]);
	}*/
	return 0;
}