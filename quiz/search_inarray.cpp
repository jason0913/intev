#include <iostream>

using namespace std;

void FastSearch(int *arr,int i,int j,int k,int l,int num)
{
	int flag =0;
	int midi,midj;
	midi = (i + k)/2;
	midj = (j + l)/2;
	if (num == *(arr + midi *10 +midj))
	{
		cout <<"FastSearch find!"<<endl;
		flag =1;
		return;
	}
	else if (num > *(arr + midi *10 +midj))
	{
		FastSearch(arr,midi,midj,k,l,num);
	}
	else
		FastSearch(arr,0,0,midi,midj,num);
	if(0 == flag)
	{
		cout <<"FastSearch not find"<<endl;
	}
}

bool Find(int *matrix,int row,int col,int num)
{
	bool flag = false;

	if(NULL != matrix && row > 0 && col >0)
	{
		if (num == *(matrix + 4*col))
		{
			flag = true;
			return flag;
		}
		else if (*(matrix + 4*col) >num)
		{
			Find(matrix,row,col-1,num);
		}
		else
			Find(matrix,row-1,col,num);
	}
	return flag;
}

int main(int argc, char const *argv[])
{
	int arr[10][10];
	int num =0;
	int n;
	int flag =0;
	bool res = false;

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			arr[i][j] = num;
			num++;
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout<<arr[i][j]<<" ";
		}
		cout <<endl;
	}
	cout<<"Input search num"<<endl;
	cin >>n;
	cout <<"search ..."<<endl;
	for (int i = 0; i < 10; ++i)
	{
		if (0 == flag)
		{
			for (int j = 0; j < 10; ++j)
			{
				if (arr[i][j] == n)
				{
					flag = 1;
					cout <<"find!"<<endl;
					break;
				}
			}
		}
		else break;
	}
	if (0 ==flag)
	{
		cout<<"not find!"<<endl;
	}
	cout <<"FastSearch------"<<endl;
	// FastSearch((int *)arr,0,0,10,10,n);
	cout <<"Find ------"<<endl;
	res =Find((int *)arr,10,10,n);
	if (false == res)
	{
		cout<<"Not Find"<<endl;
	}
	else
		cout<<"Find it"<<endl;
	return 0;
}