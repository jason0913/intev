#include <iostream>
#include <queue>

using namespace std;

class Stack
{
public:
	// Stack();
	// ~Stack();
	void push(int a);
	int pop();
private:
	queue<int> q1;
	queue<int> q2;
};

void Stack::push(int a)
{
	q1.push(a);
}

int Stack::pop()
{
	int back;
	int front;
	int res;
	if (q1.empty())
	{
		q1 = q2;
	}
	back = q1.back();
	while(back != q1.front())
	{
		q2.push(q1.front());
		q1.pop();
	}
	res = q1.back();
	q1.pop();
	return res;
}

int main(int argc, char const *argv[])
{
	Stack s;
	int len =0;
	cout<<"Input stack len"<<endl;
	cin>>len;
	for (int i = 0; i < len; ++i)
	{
		cout<<"push:"<<i<<" ";
		s.push(i);
	}
	cout<<endl;
	for (int i = 0; i < len; ++i)
	{
		cout<<"pop:"<<s.pop()<<" ";
	}
	cout<<endl;
	/*s.push(1);
	s.push(2);
	cout<<s.pop() <<" ";
	cout<<s.pop() <<" ";*/
	return 0;
}