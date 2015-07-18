#include <iostream>
#include <string>

using namespace std;

double f1()
{
	return 1.0;
}

int main(int argc, char const *argv[])
{
	string strarr[]=
	{"trend","micro","soft"};
	string *pstrarr1 = new string[2];
	pstrarr1[0]="us";
	pstrarr1[1]="cn";

	for (int i = 0; i < sizeof(strarr)/sizeof(string); ++i)
	{
		cout<<strarr[i];
	}
	cout<<endl;
	for (int j = 0; j < 2*sizeof(*pstrarr1)/sizeof(string); ++j)
	{
		cout<<pstrarr1[j];
	}
	cout<<endl;
	if (sizeof(unsigned int)== sizeof(int))
	{
		cout<<"sizeof(unsigned int)== sizeof(int)"<<endl;
	}
	cout<<"sizeof(string)"<<sizeof(string)<<endl;
	cout<<"sizeof(f1())"<<sizeof(f1())<<endl;

	return 0;
}