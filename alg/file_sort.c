#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_SIZE 1000000

void QuickSort(int a[],int numsize);
void BubbleSort(int a[],int numsize);

// global var is better than local(in stack),or use local var by malloc(in heap)
int arr[ARR_SIZE];

int main(int argc, char const *argv[])
{
	char buf[ARR_SIZE],*ptr;
	FILE *fp;
	pid_t pid;
	int i;
	int index= 0;

	fp = fopen("data.txt","r");
	if (fp == NULL)
	{
		perror("open file fail");
		exit(1);
	}
	// read data from file in this way , need move ptr
	/*while(fgets(buf,sizeof(buf),fp) != NULL)
	{
		fputs(buf,stdout);
		ptr = buf;
		while(sscanf(ptr,"%d%*c",&arr[index])!= EOF)
		{
			// printf("arr[%d]=%d \n", index,arr[index]);
			index++;
			// why ptr plus plus twice?
			ptr++;
			ptr++;
		}
	}*/
	while(fscanf(fp,"%d%*c",&arr[index])!= EOF)
	{
		// printf("arr[%d]=%d \n", index,arr[index]);
		index++;
		
	}
	printf("\nread from file\n");
	/*for (i = 0; i < index; ++i)
	{
		printf("%d ", arr[i]);
	}
	*/
	if ((pid = fork()) ==0)
	{
		// quicksort is fash than bubble,but limit 300000
		BubbleSort(arr,index/2);
		// QuickSort(arr,index/2);
		printf("\nafter sort pid:%d\n",getpid());
		for (i = 0; i < index/2; ++i)
		{
			printf("%d ", arr[i]);
		}
	}
	else
	{
		BubbleSort(arr+index/2,index/2);
		// QuickSort(arr+index/2,index/2);
		printf("\nafter sort pid:%d\n",getpid());
		for (i = index/2; i < index; ++i)
		{
			printf("%d ", arr[i]);
		}
	}
	
	return 0;
}

void BubbleSort(int a[],int numsize)
{
	int swap;
	int i,j;
	for (i = 1; i < numsize; ++i)
	{
		int flag =0;
		for (j = 0; j < i; ++j)
		{
			if (a[j] >a[i])
			{
				swap = a[j];
				a[j] = a[i];
				a[i] = swap;
				flag = 1;
			}
		}
		if (0==flag)
		{
			break;
		}
	}
}
void QuickSort(int a[],int numsize)/*a是整形数组，numsize是元素个数*/
{
	int i=0,j=numsize-1;
	int val=a[0];/*指定参考值val大小*/
	if(numsize>1)/*确保数组长度至少为2，否则无需排序*/
	{
		while(i<j)/*循环结束条件*/
		{
		/*从后向前搜索比val小的元素，找到后填到a[i]中并跳出循环*/
		for(;j>i;j--)
			if(a[j]<val)
			{
				a[i++]=a[j];
				break;
			}
		/*从前往后搜索比val大的元素，找到后填到a[j]中并跳出循环*/
		for(;i<j;i++)
			if(a[i]>val)
			{
				a[j--]=a[i];
				break;
			}
		}
		a[i]=val;/*将保存在val中的数放到a[i]中*/
		QuickSort(a,i);/*递归，对前i个数排序*/
		QuickSort(a+i+1,numsize-i-1);/*对i+1到numsize-1这numsize-1-i个数排序*/
	}
}
