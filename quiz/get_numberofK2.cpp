/*
count the times of number in array;
*/
#include <iostream>

using namespace std;

int GetFirstK(int data[],int length,int k,int start,int end)
{
	if (start >end)
	{
		return -1;
	}
	int midindex = (start +end)/2;
	int middata = data[midindex];
	if (k == middata)
	{
		if (k != data[midindex-1] && midindex >0)
		{
			return midindex;
		}
		else
		{
			end = midindex-1;
		}
	}
	else if (k < middata)
	{
		end = midindex -1;
	}
	else
		start = midindex+1;
	return GetFirstK(data,length,k,start,end);
}

int GetLastK(int data[],int length,int k,int start,int end)
{

	if (start >end)
	{
		return -1;
	}
	int midindex = (start +end)/2;
	int middata = data[midindex];
	if (k == middata)
	{
		if (k != data[midindex+1] && midindex >0)
		{
			return midindex;
		}
		else
		{
			start = midindex+1;
		}
	}
	else if (k < middata)
	{
		end = midindex -1;
	}
	else
		start = midindex+1;
	return GetLastK(data,length,k,start,end);

}
int GetNumberofK(int data[],int length,int k)
{
	if (NULL == data || length <=0)
	{
		cout<<"invalid para"<<endl;
		return -1;
	}
	int times =0;

	int first = GetFirstK(data,length,k,0,length-1);
	int last = GetLastK(data,length,k,0,length-1);
	if (first >-1 && last >-1)
	{
		times = last-first +1;
	}

	return times;
}

int main(int argc, char const *argv[])
{
	int k=3;
	int data[] ={1,2,3,3,3,3,5};
	int length = sizeof(data)/sizeof(data[0]);
	cout<<k<<" times:"<<GetNumberofK(data,length,k);
	return 0;
}