/* 
* @Author: root
* @Date:   2015-07-19 03:22:18
* @Last Modified by:   root
* @Last Modified time: 2015-07-19 03:34:20
  simple implay malloc
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void * MyMalloc(size_t size)
{
	void *ptr;
	ptr = sbrk(0);
	if ((void *)-1 == (sbrk(size)))
	{
		return NULL;
	}
	return ptr;
}
int main() {

	// char *ptr = (char *)malloc(20);
	char *ptr = (char *)MyMalloc(20);
	sprintf(ptr,"%s","this is MyMalloc");
	printf("%s\n", ptr);
    return 0;
}