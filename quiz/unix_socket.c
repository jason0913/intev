/* 
* @Author: jql
* @Date:   2015-08-29 22:05:24
* @Last Modified by:   jql
* @Last Modified time: 2015-08-29 22:18:49
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>

int main(int argc,char *argv[]) {

	int socketfd;
	socklen_t len;
	struct sockaddr_un addr1,addr2;
	if (2 != argc)
	{
		printf("usage: %s pathname\n", basename(argv[0]));
		exit(-1);
	}
	socketfd = socket(AF_LOCAL,SOCK_STREAM,0);
	bzero(&addr1,sizeof(addr1));
	addr1.sin_family = AF_LOCAL;
	strncpy(addr1.sun_path,argv[1],sizeof(addr1.sun_path)-1);
	bind(socketfd,(struct sockaddr *)&addr1,SUN_LEN(&addr1));

	len = sizeof(addr2);
	getsockname(socketfd,(struct sockaddr *)&addr2,&len);
	printf("%s  %d\n", addr2.sun_path,len);
    return 0;
}