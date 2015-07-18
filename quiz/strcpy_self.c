/*
 * =====================================================================================
 *
 *       Filename:  strcpy_self.c
 *
 *    Description:  strcpy_self
 *
 *        Version:  1.0
 *        Created:  07/10/2015 04:12:07 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char *argv[])
{
	char str[] ="abc";
	strcpy(str,str);
	printf("%s",str);
	return 0;
}
