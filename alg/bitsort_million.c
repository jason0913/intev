#include <stdio.h>
#include <stdlib.h>

#define SIZEBIT 1000
#define SIZE SIZEBIT/32 +1

void clean_all(unsigned int *bitmap)
{
	int i;
	for (i = 0; i < SIZE; ++i)
	{
		bitmap=0;
	}
}
void set(unsigned int *bitmap,unsigned int index)
{
	bitmap[index/32] |= (1 << index%32);
}

void clean(unsigned int *bitmap,unsigned int index)
{
	bitmap[index/32] &= ~(1 << index%32);
}

int get(unsigned int *bitmap,unsigned int index)
{
	return bitmap[index/32] & (1 << index%32);
}

int main(int argc, char const *argv[])
{
	unsigned int bitmap[SIZE];
	unsigned int data;
	int i;
	FILE *fp;

	// clean_all(bitmap);
	for (i = 0; i < SIZEBIT; ++i)
	{
		clean(bitmap,i);
	}
	fp = fopen("data.txt","r");
	if (NULL == fp)
	{
		perror("fopen file error");
		return -1;
	}
	while(EOF != fscanf(fp,"%d%*c",&data))
	{
		// printf("%d\n", data);
		set(bitmap,data);
	}
	fclose(fp);
	for (i = 0; i < SIZEBIT; ++i)
	{
		if (get(bitmap,i))
		{
			printf("%d ", i);
		}
	}
	return 0;
}