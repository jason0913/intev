#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// brute force alg for pattern string
#define MAXSIZE 100

typedef struct
{
	char ch[MAXSIZE];
	int length;
}SString;

int brute_force(SString S,SString T)
{
	int i,j;
	int times = 0;
	i=0;
	j=0;
	while(i <S.length && j <T.length)
	{
		if (S.ch[i] == T.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i-j+1;
			j=0;
		}
		times++;
	}
	printf("pattern times %d\n",times);
	if (j == T.length)
	{
		return 1;
	}
	else
		return 0;
	// return 0 mean no match
}
void Init_string(SString *S)
{
	/*S = (SString *)malloc(sizeof(SString));
	if (NULL == S)
	{
		perror("malloc error");
		return;
	}*/
	fgets(S->ch,sizeof(S->ch),stdin);
	S->length = strlen(S->ch);
}

int main(int argc, char const *argv[])
{
	SString S,T;
	int result;
	printf("Init_string S:\n");
	Init_string(&S);
	printf("Init_string T:\n");
	Init_string(&T);
	result = brute_force(S,T);
	if (1==result)
	{
		printf("match it\n");
	}
	else
		printf("not match\n");
	return 0;
}