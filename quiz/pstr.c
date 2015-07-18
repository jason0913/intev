#include <stdio.h>

int main()
{
	
	char *sptr;
	sptr = (char *)malloc(10*sizeof(char));
	sprintf(sptr,"hello");
	char *p =sptr;
	
	double d = 3.2;
	int n = 3;
	char arr[10] = "world";
	*(arr +3) = 'k';
	printf("%s\n",arr);
	printf("%s\n",sptr);
	*(sptr + 3) = 'k';
	sptr[2] = 'g';
	printf("%s\n",p);
	
	//printf("invald %d",(d -0.2)|n);
	return 0;
}