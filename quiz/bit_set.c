/* 
* @Author: root
* @Date:   2015-07-01 03:22:31
* @Last Modified by:   root
* @Last Modified time: 2015-07-01 03:28:39
*/

#include <stdio.h>

#define BIT_MASK(bit_pos) ((0x01 << bit_pos))

int BitSet(unsigned int *val,unsigned char pos)
{
	if (pos >= sizeof(unsigned int)*8)
	{
		return 0;
	}
	*val=(*val & ~BIT_MASK(pos));
	return 1;
}
int main() {

	unsigned int x=0xffffffff;
	unsigned char y =4;
	BitSet(&x,y);
	printf("%x\n", x);
    return 0;
}