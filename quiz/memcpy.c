#include <stdio.h>
// 传递的是指针的地址，调用函数会复制该地址，对形参指针的移动，原来的指针地址不会改变。
// 但是地址里的内容是同时改变的
void * memcpy2(char * dst,const char *src,size_t count)
{
	int i;
	printf("before:\n");
	printf("dst = %x\n",dst);
	printf("src = %x\n",src);	
	if(dst == NULL || src == NULL || count < 0)
		return NULL;
	// char *pdst = dst;
	// char *psrc = src;
	for(i = 0 ; i < count ; i++)
	{
		*dst++ = *src++;
	}
	*dst = '\0';
	printf("after:\n");
	printf("dst = %x\n",dst);
	printf("src = %x\n",src);
	return dst;
}

int main()
{
	char *p = "hello world";
	printf("before memcpy2 p = %x\n",p);
	// p++;
	printf("p++ = %x\n",p);
	char arr[100];
	printf("arr = %x\n",arr);
	memcpy2(arr,p,20);
	printf("after memcpy2 p  = %x\n",p);
	printf("%s",arr);
	return 0;
}