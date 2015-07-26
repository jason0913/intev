/* 
* @Author: root
* @Date:   2015-07-23 10:12:05
* @Last Modified by:   root
* @Last Modified time: 2015-07-25 11:17:38
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;

void FileSort(vector<int> vec)
{
	int count = vec.size();
	int i,j;
	int flag = 0;
	for (int i = 0; i < count; ++i)
	{
		flag =0;
		for (int j = 0; j < count -1; ++j)
		{
			if (vec[j] > vec[j+1])
			{
				int tmp;
				tmp = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = tmp;

				flag =1;
			}
		}
		if (0 == flag)
		{
			break;
		}
	}
}
int main(){

	vector <int> data;
	ifstream in("data.txt");
	if (! in)
	{
		cout<<"failed to open file"<<endl;
		exit(-1);
	}
	int temp;
	cout<<"get in data"<<endl;
	while(! in.eof())
	{
		in >>temp;
		cout<<temp<<" ";
		data.push_back(temp);
	}
	in.close();
	cout<<"FileSort..."<<endl;
	FileSort(data);
	ifstream out("outdata.txt");
	if (! out)
	{
		cout<<"failed to open file"<<endl;
		exit(-1);
	}
	for (int i = 0; i < data.size(); ++i)
	{
		cout<<data[i]<<" ";
	}
	out.close();
    return 0;
}