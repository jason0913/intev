/* 
* @Author: root
* @Date:   2015-07-03 22:23:51
* @Last Modified by:   root
* @Last Modified time: 2015-07-03 23:16:05
  find the lengthest seq in the array
*/

#include <iostream>

using namespace std;

int LengthestSeq(int array[],int length)
{
	if (NULL == array || length <=0)
	{
		cout<<"invalid para"<<endl;
		return 0;
	}
	int maxlen =0;
	int curlen =0;
	int indexl,indexr;
	int start =0;
	int end =0;

	while(start <= length-2)
	{
		/*if (array[start+1] == array[start])
		{
			end = start+1;
			curlen ++;
			if (curlen > maxlen)
			{
				maxlen = curlen;
			}
		}
		else
		{
			curlen=0;
			start++;
		}*/
		start = end;
		curlen =1;
		end = start;
		while(end <= length -1)
		{
			if (array[end+1] == 1+array[end])
			{
				end++;
				curlen++;
			}
			else
			{
				curlen = end-start+1;// the len = end -start+1
				if (curlen > maxlen)
				{
					maxlen = curlen;
					indexl = start;
					indexr = end;
					end++;
				}
				break;
			}
		}
	}
	for (int i = indexl; i <= indexr; ++i)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	return maxlen;
}

int main(){

	int array[] = {1,2,4,5,6,7,9,10,11,12,13};
	int length = sizeof(array)/sizeof(array[0]);

	int maxlen =0;
	maxlen = LengthestSeq(array,length);
	cout<<maxlen<<endl;

    return 0;
}