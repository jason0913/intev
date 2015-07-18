/*
two string has same char and count equal
*/
#include <iostream>
#include <string.h>

using namespace std;

bool Anagram(char *str1,char *str2)
{
	const int table_size = 256;
	bool hash_table[table_size];
	int i;
	for (i = 0; i < table_size; ++i)
	{
		hash_table[i] = false;
	}

	char *ptr1;
	char *ptr2;
	ptr1 = strlen(str1) >strlen(str2) ?str1:str2;
	while('\0'  != *ptr1)
	{
		hash_table[*ptr1] = true;
		ptr1++;
	}
	ptr2 = strlen(str1) <strlen(str2) ?str1:str2;
	while('\0' != *ptr2)
	{
		if (true == hash_table[*ptr2])
		{
			hash_table[*ptr2] =false;
		}
		ptr2++;
	}
	for (i = 0; i < table_size; ++i)
	{
		if (true == hash_table[i])
		{
			return false;
			break;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	char str1[] ="live";
	char str2[] ="evil";
	bool res = false;
	res = Anagram(str1,str2);
	if (true == res)
	{
		cout<<"Is Anagram"<<endl;
	}
	else
		cout<<"Not Anagram"<<endl;
	return 0;
}