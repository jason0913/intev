/* 
* @Author: jql
* @Date:   2015-09-01 20:54:54
* @Last Modified by:   jql
* @Last Modified time: 2015-09-01 21:05:09
*/

#include <iostream>

using namespace std;

class A
{
public:
	A()
	{
		N++,sum +=N;
	};
	static void Init()
	{
		N =0;
		sum =0;
	}
	static int GetSum()
	{
		return sum;
	}
private:
	static int N;
	static int sum;
};
int A::N =0;
int A::sum =0;

int main(){

	A::Init();
	A *pa =new A[10];
	cout<< A::GetSum()<<endl;
	delete []pa;
    return 0;
}