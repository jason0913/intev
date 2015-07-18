/*
count the times of number in array;
*/
#include <iostream>

using namespace std;

void GetNumberofK(int data[],int length)
{
	if (NULL == data || length <=0)
	{
		cout<<"invalid para"<<endl;
		return;
	}
	int i;
	const int table_size =10;
	int hash_table[table_size];
	for (i = 0; i < table_size; ++i)
	{
		hash_table[i] = 0;
	}

	for (i = 0; i < length; ++i)
	{
		hash_table[data[i]]++;
	}
	// cout the times of K
	for (i = 0; i < length; ++i)
	{
		if (hash_table[data[i]] >=1)
		{
			cout<<data[i]<<":"<<hash_table[data[i]]<<" ";
			while(hash_table[data[i]] >0)
			{
				hash_table[data[i]]--;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int data[] ={1,2,3,3,3,4,5};
	int length = sizeof(data)/sizeof(data[0]);
	GetNumberofK(data,length);
	return 0;
}