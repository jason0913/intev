/*
ugly mean : dived by 2,3,5
version2 ,this version is 40 times fast than version1
*/
#include <iostream>

using namespace std;

int Min(int n1,int n2,int n3)
{
	int min = (n1 < n2 ? n1:n2);
	min = (min < n3 ? min :n3);
	return min;
}

int GetUglyNumber(int index)
{
	if (index <0)
	{
		return 0;
	}

	int *Pugly_num =new int[index];
	Pugly_num[0] = 1;
	int next_ugly_index = 1;

	int *Pmultiply2 = Pugly_num;
	int *Pmultiply3 = Pugly_num;
	int *Pmultiply5 = Pugly_num;

	while(next_ugly_index < index)
	{
		int min = Min(*Pmultiply2 *2,*Pmultiply3 *3,*Pmultiply5 *5);
		// cout <<min<<" ";
		Pugly_num[next_ugly_index] = min;

		while(*Pmultiply2 *2 <= Pugly_num[next_ugly_index])
			++Pmultiply2;
		while(*Pmultiply3 *3 <= Pugly_num[next_ugly_index])
			++Pmultiply3;
		while(*Pmultiply5 *5 <= Pugly_num[next_ugly_index])
			++Pmultiply5;

		++next_ugly_index;
	}
	int ugly = Pugly_num[next_ugly_index-1];
	delete [] Pugly_num;
	return ugly;
}

int main(int argc, char const *argv[])
{
	int i;
	int count =1500;
	// if int i in for(),then some it is local val
	int res =0;
	res =GetUglyNumber(count);
	cout <<"res= "<<res<<endl;
	return 0;
}