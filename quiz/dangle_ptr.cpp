#include <iostream>

using namespace std;

typedef unsigned short int USHORT;

int main(int argc, char const *argv[])
{
	USHORT *pint = new USHORT;
	*pint = 10;
	cout<<"*pint"<<*pint<<endl;
	delete pint;
	pint =0;

	long *plong = new long;
	*plong =90000;
	cout<<"*plong"<<*plong<<endl;
	*pint =20;
	cout<<"*ping"<<*pint<<endl;
	cout<<"*plong"<<*plong<<endl;
	delete plong;
	return 0;
}