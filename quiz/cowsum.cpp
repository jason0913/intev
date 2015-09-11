/* 
* @Author: jql
* @Date:   2015-07-28 22:50:40
* @Last Modified by:   jql
* @Last Modified time: 2015-07-28 22:56:45
  cal the sum of cow,4 year born new 1,and each year bron 1
*/

#include <iostream>

using namespace std;

int CalCowSum(int year)
{
	int cnt =0;
	long sum =1;
	for (int cnt = 0; cnt < year; ++cnt)
	{
		if (cnt >=4)
		{
			if (year -cnt >3)
			{
				sum += CalCowSum(year -cnt);
			}
			else
				sum++;
		}
	}
	return sum;
}
int main(){

	int year=9;
	int sum =0;
	sum = CalCowSum(year);
	cout<<sum<<endl;
    return 0;
}