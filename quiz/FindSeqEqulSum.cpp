/* 
* @Author: root
* @Date:   2015-07-03 08:18:58
* @Last Modified by:   root
* @Last Modified time: 2015-07-03 22:08:16
 find a seq(size =2) in array its sum equal a value
*/

#include <iostream>

using namespace std;

// this take O(n^2)
bool FindSeqEqValue(int data[],int lenght,int sum,int *num1,int *num2)
{
	if (NULL == data || lenght <=0)
	{
		cout<<"invald para"<<endl;
		return false;
	}
	int i,j;
	for (i = 0; i < lenght-1; ++i)
	{
		for (j = i+1; j < lenght-1; ++j)
		{
			if (sum == data[i] +data[j])
			{
				cout<<data[i] <<" "<<data[j]<<endl;
				*num1 = data[i];
				*num2 = data[j];
			}
		}
	}
	if (lenght-1 == i)
	{
		return false;
	}
}
// find seq (size =3) sum equal a value
bool FindSeqEqValue3(int data[],int lenght,int sum,int *num1,int *num2,int *num3)
{
	if (NULL == data || lenght <=0)
	{
		cout<<"invald para"<<endl;
		return false;
	}
	int i,j,k;
	for (i = 0; i < lenght-3; ++i)
	{
		for (j = i+1; j < lenght-2; ++j)
		{
			for (int k = j+1; k < lenght-1; ++k)
			{
				if (sum == data[i] +data[j] +data[k])
				{
					cout<<data[i] <<" "<<data[j]<<" "<<data[k]<<endl;
					*num1 = data[i];
					*num2 = data[j];
					*num3 = data[k];
				}
			}
			
		}
	}
	if (lenght-1 == i)
	{
		return false;
	}
}
// this take O(n)
bool FindSeqEqValue2(int data[],int lenght,int sum,int *num1,int *num2)
{
	if (NULL == data || lenght <=0)
	{
		cout<<"invald para"<<endl;
		return false;
	}
	int i,j;
	i = 0;
	j = lenght-1;
	while(i <j)
	{
		if (sum == data[i] +data[j])
		{
			cout<<data[i]<<" "<<data[j]<<endl;
			*num1 = data[i];
			*num2 = data[j];
			i++;
			j--;
		}
		else if(sum < data[i]+data[j])
		{
			j--;
		}
		else
		{
			i++;
		}
	}
}
int main(){

	int data[] = {1,2,4,6,7,11,15};
	int data3[30];
	int i;
	for (int i = 0; i < 30; ++i)
	{
		data3[i] =i+1;
	}
	int lenght = sizeof(data)/sizeof(data[0]);
	int num1;
	int num2;
	int num3;
	int sum =15;
	FindSeqEqValue(data,lenght,sum,&num1,&num2);
	// cout<<num1<<" "<<num2<<endl;
	cout<<"FindSeqEqValue2-------"<<endl;
	FindSeqEqValue2(data,lenght,sum,&num1,&num2);
	cout<<"seq size :3,sum -----"<<endl;
	FindSeqEqValue3(data3,30,sum,&num1,&num2,&num3);
    return 0;
}