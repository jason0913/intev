#include <stdio.h>

int main(int argc, char const *argv[])
{
	int p=1;
	printf("%d %d %d\n", p,p,++p);
	p=1;
	printf("%d %d %d\n", p,++p,p);
	p=1;
	printf("%d %d %d\n", ++p,p,p);

	int arr[]= {6,7,8,9,10};
	int *ptr =arr;
	*(ptr++) +=123;
	printf("%d\n", *ptr);
	printf("%d\n",arr[0]);
	printf("%d %d\n", *ptr,*(++ptr));
	
	int i = 0;
    int a[] = {10,20,30};
    int r = 1 * a[i++] + 2 * a[i++] + 3 * a[i++];
    printf("r=%d,i =%d\n", r,i);

    unsigned char c =0xA5;
    unsigned char b = ~c>>4;
    unsigned char d;
    d = c*2;
    printf("b= %d,c =%x,%d\n", b,c,d);

	return 0;
}