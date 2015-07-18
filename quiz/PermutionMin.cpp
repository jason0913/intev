/*
find min num in permutaion of array
*/
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

const int MaxNumLen =10;

char *strcombine1 = new char [MaxNumLen *2 +1];
char *strcombine2 = new char [MaxNumLen *2 +1];

int compare(const void *strnumber1,const void *strnumber2)
{
	strcpy(strcombine1,(const char *)strnumber1);
	strcat(strcombine1,(const char *)strnumber2);

	strcpy(strcombine2,(const char *)strnumber2);
	strcat(strcombine2,(const char *)strnumber1);

	return strcmp(strcombine1,strcombine2);
}

void PrintMinNum(int *numbers,int length)
{
	if (NULL == numbers || length <=0)
	{
		cout<<"invalid para"<<endl;
		return;
	}
	char ** strnumber = (char **)(new int [length]);
	for (int i = 0; i < length; ++i)
	{
		strnumber[i] = new char[MaxNumLen +1];
		sprintf(strnumber[i],"%d",numbers[i]);

	}
	qsort(strnumber,length,sizeof(char),compare);
	for (int i = 0; i < length; ++i)
	{
		cout <<strnumber[i] <<" ";
	}
	cout<<endl;
	for (int i = 0; i < length; ++i)
	{
		delete [] strnumber[i];
	}
	delete [] strnumber;

}

int comp(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

int main(int argc, char const *argv[])
{
	int numbers[] = {32,321,3};
	int length = sizeof(numbers)/sizeof(numbers[0]);
	/*qsort(numbers,length,sizeof(int),comp);

	for (int i = 0; i < length; ++i)
	{
		cout <<numbers[i]<<" ";
	}*/

	cout <<"min num by permutaion"<<endl;
	PrintMinNum(numbers,length);
	return 0;
}