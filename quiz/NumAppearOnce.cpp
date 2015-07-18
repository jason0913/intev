/*
the number appear once in array
*/
#include <iostream>

using namespace std;

void NumAppearOnce(int data[],int length)
{
	if (NULL == data || length <=0)
	{
		cout<<"invalid para"<<endl;
		return;
	}
	int i,j;
	int times =0;
	for (i = 0; i < length; ++i)
	{
		times =0;
		for (j = 0; j < length; ++j)
		{
			if (data[i] == data[j])
			{
				times++;
			}
		}

		if (times <2)
		{
			cout<<data[i]<<endl;
		}
	}
	if (times >=2)
	{
		cout<<"no NumAppearOnce"<<endl;
	}
}

int main(int argc, char const *argv[])
{
	int data[] ={2,4,3,3,2,5,5,6};
	int length = sizeof(data)/sizeof(data[0]);
	NumAppearOnce(data,length);
	return 0;
}