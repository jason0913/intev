/*
show each char times in string
*/
#include <iostream>
#include <string>

using namespace std;

void CharTimes(char *str)
{
	if (NULL ==str)
	{
		cout<<"NULL string"<<endl;
		return;
	}
	const int hash_size = 256;
	int hash_table[hash_size];
	int i,j;
	char *ptr;
	for (int i = 0; i < hash_size; ++i)
	{
		hash_table[i] =0;
	}
	ptr = str;
	while('\0' !=*ptr)
	{
		++hash_table[*ptr];
		ptr++;
	}
	ptr = str;
	while('\0' !=*ptr)
	{
		if (1 <= hash_table[*ptr])
		{
			cout<<*ptr<<hash_table[*ptr];
			while(hash_table[*ptr] >0)
			{
				hash_table[*ptr]--;
			}
		}
		ptr++;
	}

}

int main(int argc, char const *argv[])
{
	char str[] = "google";
	CharTimes(str);
	return 0;
}