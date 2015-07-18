/*
two stack mock a queue
*/
#include <iostream>
#include <stack>

using namespace std;

class Queue
{
public:
	/*Queue();
	~Queue();*/
	void AppendTail(const int &a);
	int DeleteHead();
public:
	stack<int> stacka;
	stack<int> stackb;
};

void Queue::AppendTail(const int &a)
{
	stacka.push(a);
}
int Queue::DeleteHead()
{
	int res;
	if (stackb.empty())
	{
		while(!stacka.empty())
		{
			stackb.push(stacka.top());
			stacka.pop();
		}
		res = stackb.top();
		stackb.pop();
		return res;
	}
	else
	{
		res = stackb.top();
		stackb.pop();
		return res;
	}
}
int main(int argc, char const *argv[])
{
	Queue q;
	int res,len =0;
	cout<<"Input Queue len"<<endl;
	cin >>len;
	for (int i = 0; i < len; ++i)
	{
		cout<<"Enqueue:"<<i<<" ";
		q.AppendTail(i);
	}
	cout<<endl;
	cout<<"------"<<endl;
	for (int i = 0; i < len; ++i)
	{
		cout<<"Dequeue:"<<q.DeleteHead()<<" ";
	}
	cout<<endl;
	return 0;
}