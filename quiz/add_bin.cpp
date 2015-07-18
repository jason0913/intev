/* 
* @Author: root
* @Date:   2015-07-05 11:56:08
* @Last Modified by:   root
* @Last Modified time: 2015-07-05 12:13:44
*/

#include <iostream>

using namespace std;

int Add(int num1,int num2)
{
	int sum =0;
	int carry =0;
	do
	{
		sum = num1 ^num2;
		carry = (num1 &num2)<<1;

		num1 = sum;
		num2 = carry;
	}while(0 != carry);
	return sum;
}
int main(){

	int num1 =-3;
	int num2 =5;
	int sum = Add(num1,num2);
	cout<<"sum:"<<sum<<endl;
    return 0;
}