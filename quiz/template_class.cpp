#include <iostream>

using namespace std;

int jug(int x,int y)
{
	if (x >=0)
	{
		return x;
	}
	else if (0==y)
	{
		return x;
	}
	else
		return x/y;
}

int sub(int x,int y)
{
	return(x+y);
}

int minus(int x,int y)
{
	return(x-y);
}

void func_ptr(int (*p)(int,int),int a,int b)
{
	int res;
	res = (*p)(a,b);
	cout<<"a ="<<a<<" b ="<<b<<" res ="<<res<<endl;
}
// realize in static template
template <typename T>

class Operate
{
public:
	static T add(T a,T b)
	{
		return a+b;
	}
	static T mul(T a,T b)
	{
		return a*b;
	}
	static T Judge(T a,T b)
	{
		if (a >0)
		{
			return a;
		}
		else
		{
			return a/b;
		}
	}
	
};
int main(int argc, char const *argv[])
{
	int a=1,b=2,c=3,d=4,e=5;

	func_ptr(sub,a,b);
	// func_ptr(minus,d,a);
	func_ptr(jug,a,b);

	cout<<"template------"<<endl;
	cout<<Operate<int>::add(a,b)<<endl;
	cout<<Operate<int>::mul(a,b)<<endl;
	return 0;
}