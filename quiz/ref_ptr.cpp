/* 
* @Author: root
* @Date:   2015-07-26 06:33:48
* @Last Modified by:   root
* @Last Modified time: 2015-07-26 06:37:07
*/

#include <iostream>

using namespace std;

int main(){

	int a =10;
	int *ptr = &a;
	int &ra = a;
	cout<<"*ptr:"<<*ptr<<endl;
	cout<<"&ra:"<<ra<<endl;
	cout<<"-----"<<endl;

	cout<<"ptr addr:"<<ptr<<endl;
	cout<<"ra addr:"<<&ra<<endl;
	
    return 0;
}