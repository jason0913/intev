/* 
* @Author: root
* @Date:   2015-07-04 21:41:20
* @Last Modified by:   root
* @Last Modified time: 2015-07-04 21:45:38
 n person when count to m ,its out
*/

#include <iostream>

using namespace std;

int joseph(int n,int m)
{
	int fn =0;
	for (int i = 2; i <= n; ++i)
	{
		fn = (fn +m) %i;
	}
	return fn;
}

int main(){

	cout<<joseph(4,2)<<endl;
    return 0;
}