/* 
* @Author: jql
* @Date:   2015-08-12 00:26:30
* @Last Modified by:   jql
* @Last Modified time: 2015-08-12 00:35:20
*/

#include <stdio.h>

int main() {

	FILE *pfd;
	pfd = popen("rm fuckcac.tpl","r");
	char buf[1024];
	int n;
	if (NULL != pfd)
	{
		n =fread(buf,sizeof(char),1024,pfd);
		buf[n] = '\0';
		printf("n =%d\n", n);
		fputs(buf,stdout);
	}
    return 0;
}