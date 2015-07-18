/*
get the k minum int the arrary
*/

#include <iostream>
#include <algorithm>

using namespace std;

int arr[3];
int k = 2;

void GetMinK(int *input,int length)
{
	if (NULL == input || length <=0)
	{
		cout<<"invalid para"<<endl;
		return;
	}
	arr[0] =  input[0];
	arr[1] =  input[1];
	sort(arr,arr+2);
	cout <<arr[0] <<arr[1]<<endl;

	int j;
	for (int i = k; i < length; ++i)
	{
		if (input[i] > arr[1])
		{
			i++;
		}
		else
		{
			for (j = k-1; j >= 0; --j)
			{
				if (input[i] > arr[j])
				{
					break;
				}
			}
			for (int m = k-2; m > j; --m)
			{
				arr[m+1] = arr[m];
			}
			arr[j+1] = input[i];
		}
	}
}

void BubbleK(int input[],int length,int k=2)
{
	if (NULL == input || length <=0)
	{
		cout<<"invalid para"<<endl;
		return;
	}
	int i,j;
	int tmp;
	for (i = 0; i < k; ++i)
	{
		for (j = length-1; j >= 0; --j)
		{
			if (input[j-1] > input[j])
			{
				tmp = input[j-1];
				input[j-1] =  input[j];
				input[j] = tmp;
			}
		}
	}
}

/*****************************************************************************
 函 数 名  : big_heap_adjust
 功能描述  : 根据数组构建大顶堆
 输入参数  : array  待调整的堆数组
             index  待调整的数组元素的位置
             length 数组的长度
 输出参数  : 无
 返 回 值  : 无
 修改历史      :
  1.日    期   : 2012/09/10
    作    者   : liguangting
    修改内容   :
*****************************************************************************/
void big_heap_adjust(int *array, int index, int length)
{
    int child;
    int temp = array[index];

    if (2 * index + 1 >= length)
    {
        return;
    }
    //子结点位置 = 2 * 父结点位置 + 1
    child = 2 * index + 1;

    //得到子结点中较大的结点
    if (child < length - 1 && array[child + 1] > array[child])
    {
        ++child;
    }
    //如果较大的子结点大于父结点那么把较大的子结点往上移动，替换它的父结点
    if (temp < array[child])
    {
        array[index] = array[child];
    }
    else
    {
        return;
    }
    //最后把需要调整的元素值放到合适的位置
    array[child] = temp;
    big_heap_adjust(array, child, length);
}

/*****************************************************************************
 函 数 名  : find_kmax_value
 功能描述  : 查找数组中第K大元素
 输入参数  : array  待查询的数组
             length 数组的长度
             K      第K大
 输出参数  : 无
 返 回 值  : 返回第K大元素
 修改历史      :
  1.日    期   : 2012/09/10
    作    者   : liguangting
    修改内容   :
*****************************************************************************/
int find_kmax_value(int *array, int length, int k)
{
    int i = 0;

    //把子数组array[0...length-1]构造成大顶堆
    for (i = length / 2 - 1; i >= 0; i--)
    {
        big_heap_adjust(array, i, length);
    }

    //从最后一个元素开始对数组进行调整，不断缩小调整的范围直到第length - k个元素
    for (i = length - 1; i >= length - k; i--)
    {
        //交换第一个元素和当前的最后一个元素，保证当前的最后一个元素在当前数组中是最大的
        swap(array[0], array[i]);

        //调整完后的第一个元素是当前数组的最大元素
        big_heap_adjust(array, 0, i);
    }

    return array[length - k];
}

int main(int argc, char const *argv[])
{
	int input[] ={4,5,1,6,2};
	int length = sizeof(input)/sizeof(input[0]);
	GetMinK(input,length);
	cout <<arr[0] <<" " <<arr[1]<<endl;
	cout <<"BubbleK-------"<<endl;
	BubbleK(input,length);
	cout <<input[0] <<" "<<input[2]<<endl;
	cout <<"mindump-------"<<endl;
	find_kmax_value(input,length,2);
	for (int i = 0; i < length; ++i)
	{
		cout <<input[i]<<" ";
	}
	return 0;
}