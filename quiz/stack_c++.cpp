#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
	stack <int> pstack;
	for (int i = 0; i < 10; ++i)
	{
		pstack.push(i);
	}
	while(!pstack.empty())
	{
		cout <<pstack.top()<<" ";
		pstack.pop();
	}
	return 0;
}