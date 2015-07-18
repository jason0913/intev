/* 
* @Author: root
* @Date:   2015-07-13 04:45:35
* @Last Modified by:   root
* @Last Modified time: 2015-07-13 04:47:10
*/

#include <iostream>

using namespace std;

int main(){

	int i=1;
	int j = i++;
	if ((i > j++) && (i++ ==j))
	{
		i +=j;
	}
	cout<<i<<endl;
    return 0;
}