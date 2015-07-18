#include "unp.h"

#define ARR_SIZE 20

void QuickSort(int a[],int numsize);

int main(int argc, char const *argv[])
{
	int arr[ARR_SIZE];
	char buf[ARR_SIZE],*ptr;
	FILE *fp;
	int len,i;
	int fd;

	len = sizeof(arr)/sizeof(arr[0]);

/*	fp = fopen("data.txt","r");
	if (fp == NULL)
	{
		perror("open file fail");
		exit(1);
	}
	while(fgets(buf,sizeof(buf),fp) != NULL)
	{
		fputs(buf,stdout);
	}*/
	fd = open("data.txt",O_RDONLY,0666);
	if (fd == 0)
	{
		perror("open file fail");
		exit(1);
	}
	read(fd,buf,sizeof(buf));
	fputs(buf,stdout);
	write(STDOUT_FILENO,buf,sizeof(buf));
/*	printf("strlen(buf):%d\n",strlen(buf));
	ptr = buf;
	for (i = 0; i < sizeof(buf); ++i)
	{
		sscanf(ptr,"%d",&arr[i]);
		ptr++;
		printf("%d,", arr[i]);
	}*/
	QuickSort(arr,len);
	/*for (i = 0; i < len; ++i)
	{
		printf("%d \n", arr[i]);
	}*/
	return 0;
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