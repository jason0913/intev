/* 
* @Author: root
* @Date:   2015-07-05 12:14:23
* @Last Modified by:   root
* @Last Modified time: 2015-07-05 12:17:05
*/

#include <iostream>

using namespace std;

void Swap(int *a,int *b)
{
	*a = *a + *b;
	*b = *a -*b;
	*a = *a -*b;
}
int main(){

	int a=3;
	int b=5;
	Swap(&a,&b);
	cout<<a<<" "<<b<<endl;
    return 0;
}