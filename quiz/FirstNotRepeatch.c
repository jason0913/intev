/*
fisrt no repeat char in string
*/
#include <stdio.h>
#include <stdlib.h>

char FirtNoRepeatCh(char *Pstring)
{
	if (NULL == Pstring)
	{
		return '\0';
	}

	const int table_size = 256;
	unsigned int hash_table[table_size];
	int i;
	for (i = 0; i < table_size; ++i)
	{
		hash_table[i] =0;
	}

	char *phash_key = Pstring;
	while('\0' != *(phash_key))
	{
		hash_table[*phash_key]++;
		phash_key++;
	}
	phash_key = Pstring;
	while('\0' != *phash_key)
	{
		if (1== hash_table[*phash_key])
		{
			// printf("%c%d\n", *phash_key,hash_table[*phash_key]);
			return *phash_key;
		}
		phash_key++;
	}
	return '\0';
}

int main(int argc, char const *argv[])
{
	char str[] ="abaccadeff";
	char *ptr = str;
	int length = sizeof(str);

	int i,j;
	char first;
	int count;
	for (i = 0; i < length; ++i)
	{
		first = str[i];
		ptr = &str[i+1];
		count =0;
		// printf("first %c \n", first);
		while('\0' != *ptr)
		{
			// printf("ptr %c ", *ptr);
			if (first == *ptr)
			{
				count++;
				break;
			}
			++ptr;
		}
		if (0 == count)
		{
			printf("first no repeat: %c\n", str[i]);
			break;
		}
	}
	printf("optimal methon by hash_table-----\n");
	printf("first ch= %c\n",FirtNoRepeatCh(str));
	return 0;
}