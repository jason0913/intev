#include <stdio.h>
#include <stdlib.h>

#define WORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 10000000
int a[1+N/WORD];
//置位函数——用"|"操作符,i&MASK相当于mod操作
//m mod n 运算，当n = 2的X次幂的时候,m mod n = m&(n-1)
void set(int i)
{a[i>>SHIFT]|=(1<<(i&MASK));}
//清除位操作，用&~操作符
void clear(int i)
{a[i>>SHIFT]&=~(1<<(i&MASK));}
//测试位操作用&操作符
int test(int i)
{return a[i>>SHIFT]&(1<<(i&MASK));}

//---------------------main函数--------------------
int main()
{
	int i;
	FILE *fp;
	fp = fopen("data.txt","r");
	if (NULL == fp)
	{
		perror("fopen file error");
		return -1;
	}

	for(i =0 ;i< N;i++)
	{
	  clear(i);//初始化位图
	}
	while(fscanf(fp,"%d%*c",&i)!=EOF)
	{
	  set(i);
	}
	for(i =0 ;i< N;i++)
	{
	  if(test(i))
	  printf("%d ",i);
	}
	return 0;
}