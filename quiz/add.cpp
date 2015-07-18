#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int a,x;
	int p=0;
	cout<<!p <<" " <<p<<endl;
	cout<<!p++ <<" " <<p<<endl;
	cout<<!p++ <<" " <<p<<endl;
	for (a = 0,x=0; a<=1 && !x++ ; a++)
	{
		a++;
	}
	cout<<a<<" "<<x<<endl;

	for (a = 0,x=0; a<=1 && !x++ ;)
	{
		a++;
	}
	cout<<a<<" "<<x<<endl;
	return 0;
}