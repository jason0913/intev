#include <stdio.h>
#include <string.h>

void DeleteRepeatChar(char *string)
{
	if (NULL == string)
	{
		printf("string NULL\n");
		return;
	}
	char *ptr = string;
	char *ptr_next;
	// repeat char replace by space
	while('\0' != *ptr)
	{
		ptr_next = ptr;
		++ptr_next;
		while('\0' != *ptr_next)
		{
			if (*ptr == *ptr_next)
			{
				*ptr_next =' ';
			}
			ptr_next++;
		}
		ptr++;
	}
	// delete space in the string
	ptr = string;
	while('\0' != *ptr)
	{
		if (' ' ==*ptr)
		{
			ptr_next = ptr;
			char *tmp2 =ptr;
			while('\0'!= *++ptr_next)
			{
				// tmp2 = ptr_next;
				++tmp2;
				*ptr_next = *tmp2;
			}
		}
		ptr++;
	}
}

// delete repeat char by hashtable;
void DeleteRepeatChar2(char *string)
{
	const int table_size = 256;
	bool hashtable[table_size];
	int i;
	for (i = 0; i < table_size; ++i)
	{
		hashtable[i] = false;
	}
	char *ptr = string;
	while('\0' != *ptr)
	{
		if (false == hashtable[*ptr])
		{
			hashtable[*ptr] = true;
		}
		ptr++;
	}
	ptr = string;
	while('\0' != *ptr)
	{
		if (true == hashtable[*ptr])
		{
			printf("%c",*ptr);
			hashtable[*ptr] = false;
		}
		ptr++;
	}
}
int main(int argc, char const *argv[])
{
	char string[] ="google";
	// DeleteRepeatChar(string);
	printf("%s\n", string);
	printf("delete by hashtable-------\n");
	DeleteRepeatChar2(string);
	return 0;
}