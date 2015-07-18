/*
delete string1 char which appear in string2
*/
#include <stdio.h>
#include <string.h>

void DeleteString(char *str1,char *str2)
{
	/*printf("str1 =%s\n", str1);
	printf("str2 =%s\n", str2);*/
	char *ptr1,*ptr2;
	ptr1 = str1;
	while('\0' != *ptr1)
	{
		ptr2 = str2;
		while('\0' != *ptr2)
		{
			if (*ptr1 == *ptr2)
			{
				*ptr1 =' ';
			}
			ptr2++;
		}
		ptr1++;
	}
	ptr1 = str1;
	while('\0' != *ptr1)
	{
		if (' ' == *ptr1)
		{
			char *tmp = ptr1;
			char *tmp_next =++ptr1;
			while('\0' != *tmp)
			{
				*tmp = *tmp_next;
				tmp++;
				tmp_next++;
			}
		}
		++ptr1;
	}
	printf("str1 =%s\n", str1);
}

void DeleteString2(char *str1,char *str2)
{
	char *ptr2 = str2;
	char *ptr1 = str1;

	const int table_size = 256;
	int hash_table[table_size];

	for (int i = 0; i < table_size; ++i)
	{
		hash_table[i] = 0;
	}
	while('\0' != *ptr2)
	{
		++hash_table[*ptr2];
		ptr2++;
	}
	while('\0' != *ptr1)
	{
		if (hash_table[*ptr1] >=1)
		{
			*ptr1 = ' ';
		}
		ptr1++;
	}
}
int main(int argc, char const *argv[])
{
	char str1[] = "we are students";
	char str2[] ="aeiou";

	DeleteString(str1,str2);
	// DeleteString2(str1,str2);
	printf("%s\n", str1);
	return 0;
}