/* 
* @Author: root
* @Date:   2015-07-01 21:36:04
* @Last Modified by:   root
* @Last Modified time: 2015-07-01 22:03:39
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct MinStackEle
{
	int value;
	int min;

};
struct MinStack
{
	MinStackEle *data;
	int size;
	int top;
};

MinStack stack;

MinStack MinStackInit(int max)
{
	struct MinStack stack;
	stack.size = max;
	stack.top =0;
	stack.data = (MinStackEle *) malloc(sizeof(MinStackEle) *max);

	return stack;
}
void MinStackFree(MinStack stack)
{
	free(stack.data);
}
void MinStackPush(MinStack stack,int d)
{
	if (stack.top == stack.size)
	{
		cout<<"stack full"<<endl;
		return;
	}
	MinStackEle *p = stack.data[stack.top];
	p->value = d;
	p->min = (0== stack.top ? d :stack.data[stack.top-1]);
	if (p->min >d)
	{
		p->min =d;
	}
	stack.top++;
}

int MinStackPop()
{
	if (0 == stack.top)
	{
		cout<<"empty stack"<<endl;
		return -1;
	}
	return stack.data[--stack.top].value;
}
int MinStackMin()
{
	if (0 == stack.top)
	{
		cout<<"empty stack"<<endl;
		return -1;
	}
	return stack.data[--stack.top].min;
}
int main(){

	
	stack = MinStackInit(10);
	MinStackPush(stack,2);
	MinStackPush(stack,3);
	cout<<MinStackMin()<<endl;
    return 0;
}