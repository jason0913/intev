#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct 
{
	short a1;
	short a2;
	short a3;
}A;
struct 
{
	long a1;
	short a2;
	short a3;
}B;
// the difference:above 8,below 12
/*struct 
{
	short a2;
	long a1;
	short a3;
}B;*/
struct 
{
	double a1;
	int a2;
	char a3;
}C;

class A1
{
public:
	A1();
	~A1();
private:
	bool m1;
	int m2;
	bool m3;
};
class A2
{
public:
	A2();
	~A2();
private:
	int m1;
	bool m2;
	bool m3;
	// static num in global static section
	static long m;
};
int main(int argc, char const *argv[])
{
	int ss[]={1,2,3};
	char ss2[]="0987654321";
	char ss3[100]="0987654321";
	char q2[]="a\n";
	void *str2 = (void*)malloc(100);

	cout <<"strlen(ss)"<<strlen(ss)<<endl;
	cout <<sizeof(ss2)<<endl;
	cout <<sizeof(ss3)<<endl;
	cout <<"sizeof(q2)"<<sizeof(q2)<<endl;
	cout <<"sizeof(*q2)"<<sizeof(*q2)<<endl;
	cout <<sizeof(str2)<<endl;
	cout <<sizeof(A)<<endl;
	cout <<sizeof(B)<<endl;
	cout <<sizeof(C)<<endl;
	cout <<"sizeof(double)"<<sizeof(double)<<endl;
	cout <<"sizeof(long)"<<sizeof(long)<<endl;

	cout <<"sizeof(A1)"<<sizeof(A1)<<endl;
	cout <<"sizeof(A2)"<<sizeof(A2)<<endl;
	return 0;
}
