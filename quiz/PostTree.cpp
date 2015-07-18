#include <iostream>

using namespace std;

bool VerifySqueueofBST(int sequence[],int length)
{
	if (NULL == sequence || 0 >=length)
	{
		cout<< "sequence or length ==0"<<endl;
		return false;
	}
	int i,j,root;

	for (i = 0; i < length-1; ++i)
	{
		if (sequence[i] > sequence[length-1])
		{
			break;
		}
	}
	
	for (int j =i; j < length-1; ++j)
	{
		if (sequence[j] < sequence[length-1])
		{
			return false;
		}
	}
	bool left = true;
	if (i >0)
	{
		left = VerifySqueueofBST(sequence,i);
	}

	bool right = true;
	if (i < length-1)
	{
		right = VerifySqueueofBST(sequence+i,length-i-1);
	}

	return (left && right);
}

int main(int argc, char const *argv[])
{
	int sequence[] ={5,7,6,9,11,10,8};
	// int sequence[] ={7,4,6,5};
	bool res = false;
	int length;
	length = sizeof(sequence)/sizeof(sequence[0]);
	res = VerifySqueueofBST(sequence,length);
	if (true == res)
	{
		cout <<"Is BST"<<endl;
	}
	else
		cout <<"Not BST"<<endl;
	return 0;
}