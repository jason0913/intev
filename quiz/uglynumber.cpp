/*
ugly mean : dived by 2,3,5
*/
#include <iostream>

using namespace std;

bool Ugly(int number)
{
	while(0 == number %2)
	{
		number /= 2;
	}
	while(0 == number %3)
	{
		number /= 3;
	}
	while(0 == number %5)
	{
		number /= 5;
	}
	if (1 == number)
	{
		return true;
	}
	else
		return false;
}

int main(int argc, char const *argv[])
{
	int i;
	int count =0;
	// if int i in for(),then some it is local val
	for (i = 1; ; ++i)
	{
		if (true ==Ugly(i))
		{
			count++;
		}
		if (1500 == count)
		{
			// cout <<i<<endl;
			break;
		}
	}
	cout << "cout =" <<count<<endl;
	cout <<" i= "<<i<<endl;
	return 0;
}