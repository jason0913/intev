/* the file to test uncommenter functional
 * and for test 
 * result is store in commt2.c*/

#include <stdio.h>

 /*
 * =====================================================================================
 *
 *       Filename:  commt3.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/25/2015 09:27:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

// test nm and size in data size bbs etc
int arr[1000];
int global =100;
// the grobal size
int main(int argc, char const *argv[])
{
	int local =1;//the local var
	int local_arr[1000]={10};
	int local_arr2[1000];
	char *ptr;
	// int the main
	printf("sizeof(char*) %d\n", sizeof(char *));
	printf("hello world\n");
	return 0;
}
