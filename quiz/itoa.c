#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int n = 1234;
	int i =0;
	int j =0;
	int sum=0;
	char c= '9';
	char str[10];
	char str2[4] ={'4','5','6','\0'};
	char tmp[10];

	// itoa(n,str,10);
	// memset(str,0,sizeof(str));
	printf("%s\n", str);
	sprintf(str,"%d",n);
	printf("interger: %d,string = %s\n", n,str);
	printf("--------\n");

	while(n)
	{
		tmp[i] = n%10 +'0';
		i++;
		n = n/10;
	}
	// if dont has below ,then array not end
	tmp[i] = '\0';
	printf("tmp =%s\n", tmp);
	printf("----------\n");
	while(str2[j])
	{
		sum = sum *10 +(str2[j] -'0');
		j++;
	}
	printf("sum= %d\n", sum);
	printf("--------\n");
	j = j +'0';
	printf("%c\n", j);
	 c = c -'0';
	 printf("%d\n", c);
	return 0;
}
