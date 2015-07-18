/*
* @Author: root
* @Date:   2015-07-01 20:57:15
* @Last Modified by:   root
* @Last Modified time: 2015-07-01 21:26:24
	get min stack in O(1)
*/

#include <iostream>
#include <stack>

using namespace std;

stack<int> datastack;
stack<int> minstack;

void MinStackPush(int value)
{
	datastack.push(value);
	if (0 == minstack.size() || datastack.top() < minstack.top())
	{
		minstack.push(value);
	}
	else
		minstack.push(minstack.top());
}

void MinStackPop()
{
	if (datastack.size() <=0 || minstack.size() <=0)
	{
		cout<<"empty stack"<<endl;
		return;
	}
	datastack.pop();
	minstack.pop();
}

int GetMin()
{
	if (datastack.size() <=0 || minstack.size() <=0)
	{
		cout<<"empty stack"<<endl;
		return 0;
	}
	return minstack.top();
}
int main(){

	MinStackPush(3);
	MinStackPush(4);
	MinStackPush(2);
	cout<<GetMin()<<endl;
	MinStackPop();
	cout<<GetMin()<<endl;
	MinStackPush(1);
	cout<<GetMin()<<endl;
    return 0;
}